class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        back(list, new ArrayList<>(), nums);
        return list;
    }
    private void back(List<List<Integer>> list , ArrayList<Integer> tlist , int[] nums ){
        if(tlist.size() == nums.length){
            list.add(new ArrayList<>(tlist));
            return;
        }
        for(int num : nums){
            if(tlist.contains(num)) continue;
            tlist.add(num);
            back(list,tlist,nums);
            tlist.remove(tlist.size()-1);
        }
    }
}