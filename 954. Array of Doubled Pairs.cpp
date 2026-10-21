class Solution {
public:
    bool canReorderDoubled(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i:nums) mp[i]++;
        sort(nums.begin(), nums.end(), [](int a, int b){return abs(a)<abs(b);});
        for(auto el:nums){
            if(mp[el] == 0) continue;
            if(mp[2*el] == 0) return false;
            mp[el]--; mp[2*el]--;
        }
        return true;
    }
};
