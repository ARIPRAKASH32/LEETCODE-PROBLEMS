import java.util.*;
class Solution {
    public int maximumGap(int[] nums) {
        if(nums == null || nums.length <2) return 0;
        Arrays.sort(nums);
        int[] l = new int[nums.length-1];
        
        for(int i=nums.length-1 ; i >=1 ; i--){
            l[i-1] = nums[i]-nums[i-1];
        }
        int c = l[0];
        for(int  i=0 ; i<l.length ; i++){
            if(c < l[i]){
                c = l[i];
            }
        }
        return c;
    }
}
public class Leecode164 {
    public static void main(String[] args) {n
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
        int[] arr = new int[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = sc.nextInt();
	}
        Solution sol = new Solution();
	
        System.out.println(sol.maximumGap(arr));  // false
    }
}