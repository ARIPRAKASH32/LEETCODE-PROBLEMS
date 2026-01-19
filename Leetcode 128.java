class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer>set=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            set.add(nums[i]);
        }
        int maxLen=0;
        for(int element:set){
            int prev=element-1;
            if(!set.contains(prev)){
                int len=1;
                int next=element+1;
                while(set.contains(next)){
                    len++;
                    next++;
                }
                maxLen=Math.max(maxLen,len);
            }
        }
        return maxLen;
    }
}