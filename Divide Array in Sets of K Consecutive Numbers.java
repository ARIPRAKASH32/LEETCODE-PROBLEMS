class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        if(k == 1) return true;

        sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        for(auto x : nums) m[x]++;

        for(int i = 0; i<n; i++){
            int count = 0, val = nums[i];
            while(m[val] && count < k) count++, m[val]--, val++;
            if(count > 0 && count != k) return false;
        }
        return true;
    }
};
