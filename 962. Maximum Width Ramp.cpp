class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        // Stack Formation
        for (int i = 0; i < n; i++) {
            if (stk.empty() || nums[i] < nums[stk.top()]) {
                stk.push(i);
            }
        }
        int maxWidth = 0;
        // Traverse the array backwards
        for (int j = n - 1; j >= 0; j--) {
            while (!stk.empty() && nums[j] >= nums[stk.top()]) {
                maxWidth = max(maxWidth, j - stk.top());
                stk.pop();
            }
        }
        return maxWidth;
    }
};
