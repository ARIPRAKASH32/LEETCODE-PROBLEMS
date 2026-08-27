class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int count = 0;
        int length = arr.size();

        for (int i = 1; i <= length; i += 2) {
            for (int j = 0; j <= length - i; j++) {
                for (int k = j; k < j + i; k++) {
                    count += arr[k];
                }
            }
        }
        return count;
    }
};
