class Solution {
public:
    int solve(vector<int>& nums,int idx,int used,int k,vector<vector<int>>& dp,vector<int>& pre){
        int n = nums.size();
        if(idx>=n || used == 3) return 0;
        if(dp[idx][used]!=-1) return dp[idx][used];
        int notTake = solve(nums,idx+1,used,k,dp,pre);
        int take = 0;
        if(idx+k-1<n){
            take = pre[idx+k-1] - (idx>0 ? pre[idx-1] : 0) + solve(nums,idx+k,used+1,k,dp,pre);
        }
        return dp[idx][used] = max(notTake,take);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // dp + prefix sum
        vector<vector<int>>dp(n+k,vector<int>(4,-1));
        vector<int>pre(n+1,0);
        pre[0] = nums[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        // filling up the dp table
        int temp = solve(nums,0,0,k,dp,pre);
        int used = 0;
        int idx = 0;
        vector<int>res;
        while(used<3){
            int notTake = solve(nums,idx+1,used,k,dp,pre);
            int take = 0;
            if(idx+k-1<n){
                take = pre[idx+k-1] - (idx>0 ? pre[idx-1] : 0) + solve(nums,idx+k,used+1,k,dp,pre);
            }
            if(take>=notTake){
                res.push_back(idx);
                used++;
                idx+=k;
            }
            else idx++;
        }
        return res;
    }
};
