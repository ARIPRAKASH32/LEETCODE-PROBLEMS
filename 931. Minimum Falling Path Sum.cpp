class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));

        for(int j = 0; j < n; ++j) dp[n-1][j] = matrix[n-1][j];

        for(int i = n-2; i >= 0; --i){
            for(int j = 0; j < n; ++j){
                int ans = dp[i+1][j]; // below (always possible)

                // for j == 0 --> j-1 = -1 : out of bounds
                if(j > 0){ // below left
                    ans = min(ans, dp[i+1][j-1]);
                }

                // for j == n-1 --> j+1 = n : out of bounds
                if(j < n-1){ // below right
                    ans = min(ans, dp[i+1][j+1]);
                }

                dp[i][j] = ans + matrix[i][j];
                // min of all options + current cell cost
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j < n; ++j){
            ans = min(ans, dp[0][j]); 
            // answer will be stored on the first row of dp
            // as we used bottom-up :)
        }

        return ans;
    }
};
