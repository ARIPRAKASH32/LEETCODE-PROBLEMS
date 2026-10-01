class Solution {
public:
    bool rec(vector<int>&nums,vector<int>&vis,int k,int tar,int idx,int curr_sum){
        if(k==1){
            return true;
        }
        if(curr_sum==tar){
            return rec(nums,vis,k-1,tar,0,0);
        }
       
        for(int i=idx;i<nums.size();i++){
            if(vis[i]||curr_sum>tar)continue;

            vis[i]=true;
            if(rec(nums,vis,k,tar,i+1,curr_sum+nums[i]))return true;
            
            vis[i]=false;
            if(curr_sum==0)return false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(auto it:nums){
            sum+=it;
        }
        sort(nums.rbegin(),nums.rend());
        if(n<k || sum%k!=0)return false;
        vector<int>vis(n,false);
        return rec(nums,vis,k,sum/k,0,0);

    }
};
