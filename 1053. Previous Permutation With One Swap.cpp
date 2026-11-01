class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size(), i = n - 1;
        while (i > 0 && arr[i - 1] <= arr[i]) --i;
        if (i == 0) return arr;
        int j = n - 1;
        while (arr[j] >= arr[i - 1]) --j;
        while (j > i && arr[j - 1] == arr[j]) --j;
        swap(arr[i - 1], arr[j]);
        return arr;
    }
};
