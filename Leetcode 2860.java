class Solution {
    public int countWays(List<Integer> nums) {
        Collections.sort(nums);
        int way = nums.get(0) == 0 ? 0 :1;
        for(int i=0 ; i<nums.size() ; i++){
            int c = i+1;
            if(c>nums.get(i) && (i+1 == nums.size() || c<nums.get(i+1)))
                way++;
        }
        return way;
    }

}