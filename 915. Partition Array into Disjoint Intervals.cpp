class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> pfx(n, 0);
        vector<int> sfx(n, 0);
        pfx[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pfx[i] = max(nums[i], pfx[i - 1]);
        }
        sfx[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sfx[i] = min(nums[i], sfx[i + 1]);
        }
        for (int i = 0; i < n - 1; i++) {
            if (pfx[i] <= sfx[i + 1]) {
                return i + 1;
            }
        }
        
        return -1;
    }
};
