class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int ans=INT_MAX;

        unordered_set<int> dp;
        dp.insert(0);

        for(int i=0; i<stones.size(); i++){
            unordered_set<int> newdp;

            for(int diff:dp){
            newdp.insert(diff+stones[i]);
            newdp.insert(diff-stones[i]);
            }

            dp=newdp;
        }

        for(auto it: dp)
            ans=min(ans, abs(it));

        return ans;
    }
};
