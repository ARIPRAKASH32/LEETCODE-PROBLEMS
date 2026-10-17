class Solution {
public:
    int digSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end(), [&](auto x, auto y) {
            int a = digSum(x.first);
            int b = digSum(y.first);

            if (a != b) return a < b;
            return x.first < y.first;
        });

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        vector<bool> fix(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (fix[i]) continue;

            int j = i, count = 0;

            while (!fix[j]) {
                fix[j] = true;
                j = pos[j];
                count++;
            }

            if (count > 1) {
                swaps += count - 1;
            }
        }

        return swaps;
    }
};
