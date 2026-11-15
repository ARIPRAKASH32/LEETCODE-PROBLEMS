#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxi = -1;
        
        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = maxi;
            maxi = max(maxi, temp);
        }
        
        return arr;
    }
};
