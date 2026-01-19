import java.util.*;
class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int max = nums[0];
        for(int i=0 ; i<n ; i++){
            if(max > nums[i]){
                max = nums[i];
            }
        }
        return max;
    }
}
public class Leecode153 {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
        int[] arr = new int[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = sc.nextInt();
	}
        Solution sol = new Solution();
	
        System.out.println(sol.findMin(arr));  // false
    }
}