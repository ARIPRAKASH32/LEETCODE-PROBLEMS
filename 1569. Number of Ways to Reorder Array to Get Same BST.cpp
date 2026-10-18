class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    vector<vector<long long>> comb;

    long long count(const vector<int>& arr) {
        int n = arr.size();

        if (n <= 2) {
            return 1;
        }

        int root = arr[0];

        vector<int> left, right;

        for (int x : arr) {
            if (x < root) {
                left.push_back(x);
            } else if (x > root) {
                right.push_back(x);
            }
        }

        int L = left.size();
        int R = right.size();

        long long ways = comb[L + R][L];

        return ways * count(left) % MOD * count(right) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (count(nums) - 1 + MOD) % MOD;
    }
};
