#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }
        vector<int> sum(maxVal + 1, 0);
        for (int num : nums) {
            sum[num] += num;
        }

      
        vector<int> dp(maxVal + 1, 0);
        dp[0] = sum[0];
        dp[1] = max(sum[0], sum[1]);

        for (int i = 2; i <= maxVal; i++) {
            int pick = sum[i] + dp[i - 2];
            int npick = dp[i - 1];
            dp[i] = max(pick, npick);
        }

        return dp[maxVal];
    }
};
