import java.util.*;
class Solution {
    public int minPatches(int[] nums, int n) {
    
        long m = 1;
        int result = 0;
        int i = 0;

        while (m <= n) {
            if (i < nums.length && nums[i] <= m) {
                m += nums[i];
                i++;
            } else {
                m += m;
                result++;
            }
        }

        return result;
 
    }
}
public class Leetcode330{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int low = sc.nextInt();
		int n = sc.nextInt();
		int [] arr = new int[low];
		for(int i=0 ; i<low ; i++){
			arr[i]= sc.nextInt();
		}		
		Solution sol = new Solution();
		System.out.println(sol.minPatches(arr,n));
	}
}