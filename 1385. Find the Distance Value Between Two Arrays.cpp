class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;

        for (int num : arr1) {
            int left = -1, right = static_cast<int>(arr2.size());
            bool found = false;

            while (right - left > 1) {
                int mid = left + (right - left) / 2;
                if (abs(num - arr2[mid]) <= d) {
                    found = true;
                    break;
                }
                if (arr2[mid] < num) left = mid;
                else right = mid;
            }

            if (!found) ++ans;
        }

        return ans;
    }
};
