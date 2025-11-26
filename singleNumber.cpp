#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (umap[nums[i]] == 1) {
                return nums[i];
            }
        }
                return -1;
    }
};
