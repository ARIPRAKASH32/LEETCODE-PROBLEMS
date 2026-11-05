class Solution {
public:
    int maxAbsValExpr(vector<int>& a, vector<int>& b) {

        int n = a.size();

        int c1Max = INT_MIN, c1Min = INT_MAX;
        int c2Max = INT_MIN, c2Min = INT_MAX;
        int c3Max = INT_MIN, c3Min = INT_MAX;
        int c4Max = INT_MIN, c4Min = INT_MAX;

        // Case 1 : a[i] + b[i] + i
        for (int i = 0; i < n; i++) {
            c1Max = max(c1Max, a[i] + b[i] + i);
            c1Min = min(c1Min, a[i] + b[i] + i);
        }

        // Case 2 : -a[i] + b[i] + i
        for (int i = 0; i < n; i++) {
            c2Max = max(c2Max, b[i] - a[i] + i);
            c2Min = min(c2Min, b[i] - a[i] + i);
        }

        // Case 3 : a[i] - b[i] + i
        for (int i = 0; i < n; i++) {
            c3Max = max(c3Max, a[i] - b[i] + i);
            c3Min = min(c3Min, a[i] - b[i] + i);
        }

        // Case 4 : -a[i] - b[i] + i
        for (int i = 0; i < n; i++) {
            c4Max = max(c4Max, i - a[i] - b[i]);
            c4Min = min(c4Min, i - a[i] - b[i]);
        }

        return max(
            max(c1Max - c1Min, c2Max - c2Min),
            max(c3Max - c3Min, c4Max - c4Min)
        );
    }
};
