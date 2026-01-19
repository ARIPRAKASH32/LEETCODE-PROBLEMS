import java.util.*;
class Solution {
    public int absDifference(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int maxsum = 0;
        int minsum = 0;
        for(int i=0 ; i<k ; i++){
            minsum += nums[i];
        }
        for(int i=n-k ; i<n ; i++){
            maxsum += nums[i];
        }
        return Math.abs(maxsum - minsum);
    }
}
public class Leetcode3774{
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int [] arr = new int[n];
		for(int i=0 ; i<n ; i++)
		{
			arr[i] = sc.nextInt();
		}
		Solution sol = new Solution();
		System.out.println(sol.numberOfWays(arr , k));
	}
}