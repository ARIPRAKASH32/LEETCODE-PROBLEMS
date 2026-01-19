class Solution {
public:
    long long rec(int man,int low, int high,vector<vector<vector<int>>>&dp,vector<int>&piles){
        if(dp[man][low][high]!=-1) return dp[man][low][high];
        if(low==high) return 0;
        if(man&1){
            dp[man][low][high]=min(rec(man^1,low+1,high,dp,piles),rec(man^1,low,high-1,dp,piles));
        }
        return dp[man][low][high]=max(piles[low]+rec(man^1,low+1,high,dp,piles),piles[high]+rec(man^1,low,high-1,dp,piles));
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int tot=accumulate(piles.begin(),piles.end(),0);
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        bool f1=true;
        long long z=rec(0,0,n-1,dp,piles);
        if(z>tot/2) return true;
        return false;
    }
};
