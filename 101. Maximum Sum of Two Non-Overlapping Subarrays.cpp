class Solution {
public:

    int helper(vector<int>& nums, int first, int second) {

        int n = nums.size();

        int sumFirst = 0, sumSecond = 0;

        for (int i = 0; i < first; i++)
            sumFirst += nums[i];

        for (int i = first; i < first + second; i++)
            sumSecond += nums[i];

        int result = sumFirst + sumSecond;
        int bestFirst = sumFirst;

        for (int j = first + second; j < n; j++) {

            // Slide both windows.
            sumFirst += nums[j - second] - nums[j - first - second];
            sumSecond += nums[j] - nums[j - second];

            bestFirst = max(bestFirst, sumFirst);
            result = max(result, bestFirst + sumSecond);
        }

        return result;
    }

    int maxSumTwoNoOverlap(vector<int>& nums,
                           int firstLen,
                           int secondLen) {

        return max(
            helper(nums, firstLen, secondLen),
            helper(nums, secondLen, firstLen)
        );
    }
};
