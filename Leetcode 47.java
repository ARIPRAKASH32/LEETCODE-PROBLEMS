class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums); 
        boolean[] used = new boolean[nums.length];
        back(list, new ArrayList<>(), nums,used);
        return list;
    }
    private void back(List<List<Integer>> list , ArrayList<Integer> tlist , int[] nums , boolean[] used ){
        if(tlist.size() == nums.length){
            list.add(new ArrayList<>(tlist));
            return;
        }
        for(int i=0 ; i<nums.length ; i++){
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            tlist.add(nums[i]);
            back(list , tlist , nums,used);
            used[i] = false;
            tlist.remove(tlist.size()-1);
        }
    }
}