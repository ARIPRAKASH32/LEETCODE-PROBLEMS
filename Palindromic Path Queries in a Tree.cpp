#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FenwickTree {
    vector<int> tree;
    int n;
public:
    FenwickTree(int n) : n(n), tree(n + 2, 0) {}
    
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] ^= val;
        }
    }
    
    void updateRange(int l, int r, int val) {
        add(l, val);
        add(r + 1, val);
    }
    
    int queryPoint(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= tree[idx];
        }
        return res;
    }
};

class Solution {
    int timer;
    vector<int> in_time, out_time, depth;
    vector<vector<int>> up;
    int LOG;

    void dfs(int u, int p, const vector<vector<int>>& adj, const string& s, int current_mask, FenwickTree& bit) {
        in_time[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i) {
            if (up[u][i - 1] != -1) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            } else {
                up[u][i] = -1;
            }
        }
        int node_mask = 1 << (s[u] - 'a');
        current_mask ^= node_mask;
        bit.updateRange(in_time[u], in_time[u], current_mask);

        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, adj, s, current_mask, bit);
            }
        }
        out_time[u] = timer;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        timer = 0;
        LOG = 32 - __builtin_clz(n);
        in_time.resize(n);
        out_time.resize(n);
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, -1));
        FenwickTree bit(n);
        dfs(0, -1, adj, s, 0, bit);
        vector<char> current_chars(s.begin(), s.end());
        vector<bool> ans;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int old_mask = 1 << (current_chars[u] - 'a');
                int new_mask = 1 << (c - 'a');
                int change = old_mask ^ new_mask;
                bit.updateRange(in_time[u], out_time[u], change);
                current_chars[u] = c;
            } else {
                int u, v;
                ss >> u >> v;

                int lca = get_lca(u, v);
                int mask_u = bit.queryPoint(in_time[u]);
                int mask_v = bit.queryPoint(in_time[v]);
                int mask_lca_char = 1 << (current_chars[lca] - 'a');
                int path_mask = mask_u ^ mask_v ^ mask_lca_char;
                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }

        return ans;
    }
};
