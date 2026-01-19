class Solution {
public:
    int minimumBoxes(int n) {
        int bottom = 1, total = 1, h = 1;
        while (total + bottom + h + 1 <= n) {
            bottom += ++h;
            total += bottom;
        }
        int r = n - total, L = 0, R = h + 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if ((1 + M) * M / 2 >= r) R = M - 1;
            else L = M + 1;
        }
        return bottom + L;
    }
};