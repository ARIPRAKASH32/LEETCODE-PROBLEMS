class Solution {
    public int[] singleNumber(int[] nums) {
        ArrayList<Integer> li = new ArrayList<>();
       
        for(int i=0 ; i<nums.length ; i++){
             boolean b = false;
            for(int j=0 ; j<nums.length ; j++){
                if(nums[i]==nums[j] && i!=j){
                     b=true;
                     break;
                }

            }
            if(!b){
                li.add(nums[i]);
                if(li.size()==2){
                    break;
                }
            }
        }
        int [] ar = new int[li.size()];
        for(int i=0 ; i<ar.length ; i++){
            ar[i] = li.get(i);
        }

        return ar;
    }
}
public class Leecode260 {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
        int[] arr = new int[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = sc.nextInt();
	}
        Solution sol = new Solution();
	
        System.out.println(sol.SingleNumber(arr));  // false
    }
}