class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        long sum = 0;
        int kk = k / 2, n = prices.length;
        long current = 0, max = 0;
        for(int i = 0; i < kk; i++) {
            int val = prices[i] * strategy[i];
            sum += val;
            current += prices[i] - val;
        }
        for(int i = kk; i < k; i++) {
            int val = prices[i] * strategy[i];
            sum += val;
            current += prices[i] - val - prices[i - kk];
        }
        max = Math.max(max, current);
        for(int i = k; i < n; i++) {
            int val = prices[i] * strategy[i];
            sum += val;
            current += prices[i] - val - prices[i - kk] + prices[i - k] * strategy[i - k];
            max = Math.max(max, current);
        }
        return sum + max;
    }
}
public class Leetcode3652 {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
        int[] arr = new int[n];
	int m = sc.nextInt();
        int[] arr1 = new int[n];

	int l = sc.nextInt();
        int[] arr = new int[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = sc.nextInt();
	}
	for(int i=0 ; i<n ; i++)
	{
		arr1[i] = sc.nextInt();
	}
        Solution sol = new Solution();
	
        System.out.println(sol.maxProfit(arr,arr1,l));      }
}