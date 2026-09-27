class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {// TC : O(N) + O(NlogN) + O(N) + O(N) = O(NlogN) & SC : O(N)
        vector<int>temp = nums;// TC : O(N)

        sort(nums.begin(),nums.end());// TC : O(NlogN)

        if(temp == nums){
            return 0;
        }

        int st = 0;
        int end = nums.size()-1;

        while(st<nums.size()-1){// O(N)
            if(temp[st] == nums[st]){
                st++;
            }else{
                break;
            }
        }

        while(end>=0){// O(N)
            if(temp[end] == nums[end]){
                end--;
            }else{
                break;
            }
        }

        return end-st+1;
    }
};
