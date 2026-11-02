class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        int k = 0;

        for (int num : arr) {
            if (k == arr.size()) {
                break;
            }

            if (num == 0) {
                ans[k++] = 0;

                if (k == arr.size()) {
                    break;
                }

                ans[k++] = 0;
            } else {
                ans[k++] = num;
            }
        }

        arr = ans;
    }
};
