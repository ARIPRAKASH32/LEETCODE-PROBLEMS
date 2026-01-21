import java.util.*;
class Solution {
    public long getDescentPeriods(int[] prices) {
        int n = prices.length;
        long c = 1;
        int t = 1;
        for(int i=1 ; i<n ; i++){
            if(prices[i-1] - prices[i] == 1) t++;
            else t=1;
            c+=t;
        }
        return c;
    }
}
public class Leetcode2110 {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
        int[] arr = new int[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = sc.nextInt();
	}
        Solution sol = new Solution();
	
        System.out.println(sol.getDescentPeriods(arr));      }
}