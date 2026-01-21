class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> list=new ArrayList<>();
        Map<Integer,Integer> map=new HashMap<>();
        for(int val:nums){
            map.put(val,map.getOrDefault(val,0)+1);
        }
        int n=nums.length/3;
        for(var e:map.entrySet()){
            
            if(e.getValue()>n)list.add(e.getKey());
        }
        return list;
    }
}