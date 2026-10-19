class Solution {
public:
    const int MOD = 1e9 + 7;
    int t[5001][10];

    vector<vector<int>> adj = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                               {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    int solve(int n, int cell) {
        if (n == 0)
            return 1;

        if (t[n][cell] != -1)
            return t[n][cell];

        int ans = 0;
        for (int j = 0; j < adj[cell].size(); j++) {
            int neigh = adj[cell][j];
            ans = (ans + solve(n - 1, neigh)) % MOD;
        }

        return t[n][cell] = ans % MOD;
    }

    int knightDialer(int n) {
        int result = 0;
        memset(t, -1, sizeof(t));
        for (int cell = 0; cell <= 9; cell++) {
            result = (result + solve(n - 1, cell)) % MOD;
        }
        return result % MOD;
    }
};
