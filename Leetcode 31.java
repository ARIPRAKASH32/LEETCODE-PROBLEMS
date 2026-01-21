class Solution {
    public void nextPermutation(int[] nums) {
        int in = -1;
        int in1 = -1;
        int n = nums.length;
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                in = i;
                break;
            }
        }
        if(in == -1){
            reverse(nums,0);
            
        }
        else{
            for(int i=n-1 ; i>=0;i--){
                if(nums[i]>nums[in]){
                    in1 = i;
                    break;
                }
            }
            swap(nums,in , in1);
            reverse(nums,in+1);
        }
    }
    void swap(int[]nums , int i , int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    void reverse(int []nums,int start){
        int i=start;
        int j=nums.length-1;
        while(i<j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }
}