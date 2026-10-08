class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> state(graph.size(), 0);
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {

            if (dfs(graph, state, i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    bool dfs(
        vector<vector<int>>& graph,
        vector<int>& state,
        int idx
    ) {
        if (state[idx] == 2) {
            return true;
        }
        if (state[idx] == 3) {
            return false;
        }
        if (state[idx] == 1) {
            return false;
        }
        state[idx] = 1;

        for (int neighbor : graph[idx]) {
            if (!dfs(graph, state, neighbor)) {
                state[idx] = 3;
                return false;
            }
        }
        state[idx] = 2;
        return true;
    }
};
