class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(maxSum(nums, firstLen, secondLen),
                   maxSum(nums, secondLen, firstLen));
    }

    int maxSum(vector<int>& nums, int L, int R) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];

        int maxL = 0, result = 0;
        for (int i = L + R; i <= n; ++i) {
            maxL = max(maxL, prefix[i - R] - prefix[i - R - L]);
            result = max(result, maxL + prefix[i] - prefix[i - R]);
        }
        return result;
    }
};
