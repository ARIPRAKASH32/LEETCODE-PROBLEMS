class SegmentTree {
private:
    vector<int> segTree, lazy;
    int size;

    void build(int i, int l, int r) {
        if (l == r) {
            segTree[i] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid);
        build(2 * i + 2, mid + 1, r);
    }

    void push(int i, int l, int r) {
        if (lazy[i]) {
            segTree[i] = max(segTree[i], lazy[i]);
            if (l != r) {
                lazy[2 * i + 1] = max(lazy[2 * i + 1], lazy[i]);
                lazy[2 * i + 2] = max(lazy[2 * i + 2], lazy[i]);
            }
            lazy[i] = 0;
        }
    }

    int query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return segTree[i];
        int mid = (l + r) / 2;
        return max(query(2 * i + 1, l, mid, ql, qr),
                   query(2 * i + 2, mid + 1, r, ql, qr));
    }

    void update(int i, int l, int r, int ql, int qr, int h) {
        push(i, l, r);
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            lazy[i] = max(lazy[i], h);
            push(i, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * i + 1, l, mid, ql, qr, h);
        update(2 * i + 2, mid + 1, r, ql, qr, h);
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

public:
    SegmentTree(int n) {
        size = n;
        segTree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(0, 0, size - 1);
    }

    int query(int l, int r) { return query(0, 0, size - 1, l, r); }

    void update(int l, int r, int h) { update(0, 0, size - 1, l, r, h); }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> coordinates;

        // Coordinate compression
        for (auto& p : positions) {
            coordinates.insert(p[0]);
            coordinates.insert(p[0] + p[1]);
        }

        unordered_map<int, int> index;
        int idx = 0;
        for (int x : coordinates)
            index[x] = idx++;

        SegmentTree st(idx);
        vector<int> ans;
        int max_height = 0;

        for (auto& p : positions) {
            int l = index[p[0]];
            int r = index[p[0] + p[1]] - 1;
            int curr_height = st.query(l, r);
            int new_height = curr_height + p[1];
            st.update(l, r, new_height);
            max_height = max(max_height, new_height);
            ans.push_back(max_height);
        }

        return ans;
    }
};
