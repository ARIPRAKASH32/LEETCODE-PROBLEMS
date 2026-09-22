class Solution {
public:
    static const int MAXSZ = 1 << 18;              // covers 2*size for n up to 1e5
    static inline int prodArr[MAXSZ];
    static inline int freqArr[MAXSZ * 5];           // fixed stride 5 (k <= 5)
    static inline int mulmod[5][5];

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        int size = 1;
        while (size < n) size <<= 1;

        for (int a = 0; a < k; a++)
            for (int b = 0; b < k; b++)
                mulmod[a][b] = (a * b) % k;

        auto setLeaf = [&](int pos, long long val) {
            int r = (int)(val % k);
            prodArr[pos] = r;
            int base = pos * 5;
            for (int i = 0; i < k; i++) freqArr[base + i] = 0;
            freqArr[base + r] = 1;
        };
        for (int i = 0; i < n; i++) setLeaf(size + i, nums[i]);

        auto combineInto = [&](int node, int l, int r) {
            int lp = prodArr[l], rp = prodArr[r];
            prodArr[node] = mulmod[lp][rp];
            int nb = node * 5, lb = l * 5, rb = r * 5;
            for (int i = 0; i < k; i++) freqArr[nb + i] = freqArr[lb + i];
            for (int i = 0; i < k; i++) {
                int c = freqArr[rb + i];
                if (c) freqArr[nb + mulmod[lp][i]] += c;
            }
        };
        for (int i = size - 1; i >= 1; i--) combineInto(i, 2 * i, 2 * i + 1);

        auto update = [&](int idx, int val) {
            int pos = size + idx;
            setLeaf(pos, val);
            pos >>= 1;
            while (pos >= 1) { combineInto(pos, pos << 1, pos << 1 | 1); pos >>= 1; }
        };

        int lf[5], rf[5];
        auto query = [&](int l, int r, int x) -> int {
            int lp = 1 % k, rp = 1 % k;
            for (int i = 0; i < k; i++) { lf[i] = 0; rf[i] = 0; }
            l += size; r += size;
            while (l < r) {
                if (l & 1) {
                    int base = l * 5;
                    for (int i = 0; i < k; i++) {
                        int c = freqArr[base + i];
                        if (c) lf[mulmod[lp][i]] += c;   // accumulate in place, no temp needed
                    }
                    lp = mulmod[lp][prodArr[l]];
                    l++;
                }
                if (r & 1) {
                    r--;
                    int base = r * 5, pr = prodArr[r];
                    int tmp[5];
                    for (int i = 0; i < k; i++) tmp[i] = freqArr[base + i];
                    for (int i = 0; i < k; i++) {
                        int c = rf[i];
                        if (c) tmp[mulmod[pr][i]] += c;
                    }
                    for (int i = 0; i < k; i++) rf[i] = tmp[i];
                    rp = mulmod[pr][rp];
                }
                l >>= 1; r >>= 1;
            }
            int res[5] = {0, 0, 0, 0, 0};
            for (int i = 0; i < k; i++) res[i] = lf[i];
            for (int i = 0; i < k; i++) {
                int c = rf[i];
                if (c) res[mulmod[lp][i]] += c;
            }
            return res[x];
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            update(q[0], q[1]);
            ans.push_back(query(q[2], n, q[3]));
        }
        return ans;
    }
};
