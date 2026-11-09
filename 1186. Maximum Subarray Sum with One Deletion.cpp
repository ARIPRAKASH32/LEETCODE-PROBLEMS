class Solution {
public:
    #define ll long long

    class Node {
    public:
        ll sum;
        ll pref;
        ll suf;
        ll res;

        Node() {
            this->sum = -4e18;
            this->pref = -4e18;
            this->suf = -4e18;
            this->res = -4e18;
        }
    };

    vector<Node> seg;
    Node a;

    void merge(Node& c, Node& l, Node& r) {
        c.sum = l.sum + r.sum;
        c.pref = max(l.pref, l.sum + r.pref);
        c.suf = max(r.suf, r.sum + l.suf);
        c.res = max({l.res, r.res, l.suf + r.pref});
    }

    void build(vector<int>& v, int node, int l, int r) {
        if (l == r) {
            seg[node].sum = seg[node].pref =
            seg[node].suf = seg[node].res = v[l];
            return;
        }

        int mid = (l + r) >> 1;

        build(v, 2 * node, l, mid);
        build(v, 2 * node + 1, mid + 1, r);

        merge(seg[node], seg[2 * node], seg[2 * node + 1]);
    }

    Node f(Node& l, Node& r) {
        Node c;

        c.sum = l.sum + r.sum;
        c.pref = max(l.pref, l.sum + r.pref);
        c.suf = max(r.suf, r.sum + l.suf);
        c.res = max({l.res, r.res, l.suf + r.pref});

        return c;
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return a;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) >> 1;

        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);

        if (left.sum == -4e18)
            return right;

        if (right.sum == -4e18)
            return left;

        return f(left, right);
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        seg.clear();
        seg.resize(4 * n, Node());

        // Maximum subarray sum of the original array
        ll csum = 0;
        ll res = -1e18;

        for (int i = 0; i < n; i++) {
            csum += nums[i];
            res = max(res, csum);
            csum = max(0LL, csum);
        }

        build(nums, 1, 0, n - 1);

        // Remove each element once
        for (int i = 0; i < n; i++) {

            if (i == 0) {
                Node right = query(
                    1, 0, n - 1,
                    1, n - 1
                );

                res = max(res, right.res);
            }

            else if (i == n - 1) {
                Node left = query(
                    1, 0, n - 1,
                    0, n - 2
                );

                res = max(res, left.res);
            }

            else {
                Node left = query(
                    1, 0, n - 1,
                    0, i - 1
                );

                Node right = query(
                    1, 0, n - 1,
                    i + 1, n - 1
                );

                res = max({
                    res,
                    left.res,
                    right.res,
                    left.suf + right.pref
                });
            }
        }

        return res;
    }
};
