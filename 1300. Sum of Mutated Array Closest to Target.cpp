class Solution {
public:
    long long function(int x, vector<int>& arr, int target){
        long long running_sum = 0;

        for (int a: arr){
            if (a > x){
                running_sum += x;
            } else {
                running_sum += a;
            }
        }

        return running_sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        int low = 1, high = *max_element(arr.begin(),arr.end());

        while (low <= high){
            int mid = (low+high)/2;

            if (function(mid,arr,target) <= target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (abs(function(low,arr,target)-target) < abs(function(high,arr,target)-target)){
            return low;
        }

        return high;
    }
};
