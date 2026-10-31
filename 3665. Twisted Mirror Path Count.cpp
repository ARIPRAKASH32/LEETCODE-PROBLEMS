constexpr int mod=1e9+7;
int dp[2][500][2];// dp[i][j][dir] where dir=0/1 stand for right/down
using ll=long long;
class Solution {
public:
    static int uniquePaths(vector<vector<int>>& grid) {
        const int r=grid.size(), c=grid[0].size();
        memset(dp[0], 0, (c*2)*sizeof(int));
        memset(dp[1], 0, (c*2)*sizeof(int));
        // 0th row
        for(int j=0; j<c; j++){
            dp[0][j][0]=1;
            if (grid[0][j]) break;
        }
        bool isM=0;
        for(int i=1; i<r; i++){
            //0th col
            const bool cur=i&1;
            dp[cur][0][1]=!isM;
            isM|=grid[i][0];

            for(int j=1; j<c; j++){
                for(auto dir=0; dir<=1; dir++){
                    if (grid[i][j]){
                        dp[cur][j][dir]=dp[cur^dir][j-!dir][!dir];
                        continue;
                    }
                    ll step=dp[cur][j-1][1]+dp[!cur][j][0];
                    if (step>=mod) step%=mod;
                    dp[cur][j][dir]=step;
                }
            }
        }
        return dp[(r-1)&1][c-1][0];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
