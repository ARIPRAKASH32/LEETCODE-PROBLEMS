class Solution {
public:
    int numRollsToTarget(int d, int k, int target) {
        const int MOD = 1000000007;
        vector<int> dp(target+1,0);
        dp[0] = 1;
        while(d--){
            vector<int> temp(target+1,0);
            int x=0;
            for (int j=1;j<=target;j++) {
                x = (x+dp[j-1])%MOD;
                if(j-k-1>=0) x=(x-dp[j-k-1]+MOD)%MOD;
                temp[j] = x;
            }
            dp = temp;
        }
        return dp[target];
    }
};
