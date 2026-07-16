class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGCD(nums.size());

        long long sumGcd = 0;
        int mx = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            prefixGCD[i] = gcd(mx, nums[i]);
        }

        sort(prefixGCD.begin(), prefixGCD.end());

        int i = 0, j = prefixGCD.size() - 1;

        while (i < j) {
            sumGcd += gcd(prefixGCD[i], prefixGCD[j]);
            i++;
            j--;
        }

        return sumGcd;
    }
};
