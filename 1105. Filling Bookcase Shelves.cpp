class Solution {
public:
    int fact(int i, vector<vector<int>>& books, int sw, vector<int>& dp) {

        if (i < 0) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int width = 0;
        int height = 0;
        int ans = INT_MAX;

        for (int j = i; j >= 0; j--) {

            width += books[j][0];

            if (width > sw) {
                break;
            }

            height = max(height, books[j][1]);

            ans = min(ans, height + fact(j - 1, books, sw, dp));
        }

        return dp[i] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        int n = books.size();

        int sw = shelfWidth;

        vector<int> dp(n, -1);

        return fact(n - 1, books, sw, dp);
    }
};
