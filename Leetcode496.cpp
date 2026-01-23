class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for(int i = 0; i < nums1.size(); i++) {
            int curr = nums1[i];
            int ans = -1;
            bool found = false;

            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] == curr) {
                    found = true;
                }
                else if(found && nums2[j] > curr) {
                    ans = nums2[j];
                    break;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};
