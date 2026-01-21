class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int len = nums.length;
        int []res = new int[len];
        int leftre = 0 ;


        for (int i = 0; i < len; i++) {
            if (nums[i] < pivot) {
                res[leftre++] = nums[i];
            }
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] == pivot) {
                res[leftre++] = nums[i];
            }
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] > pivot) {
                res[leftre++] = nums[i];
            }
        }
        return res;
    }
}