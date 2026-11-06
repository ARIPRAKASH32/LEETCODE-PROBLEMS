class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int res[2] = {0, 0};
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int left = i ? nums[i - 1] : INT_MAX;
            int right = (i + 1 < n) ? nums[i + 1] : INT_MAX;
            int minAdj = min(left, right);
            if (nums[i] >= minAdj) res[i & 1] += nums[i] - minAdj + 1;
        }
        return min(res[0], res[1]);
    }
};
