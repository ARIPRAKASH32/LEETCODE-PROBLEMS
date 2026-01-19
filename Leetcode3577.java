class Solution {
    static int mod = 1000000007;
    public int countPermutations(int[] complexity) {
        int n = complexity.length;
        int forst = complexity[0];

        for(int i = 1 ; i< n ; i++){
            if(complexity[i] <= forst) {
                return 0;
            }
        }
        long fact = 1; 
        for(int i = 2 ; i<n ; i++){
            fact = (fact*i)%mod;
        }
        return (int)fact;
    }
}
public class Leetcode3577 {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
        int[] arr = new int[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = sc.nextInt();
	}
        Solution sol = new Solution();
	
        System.out.println(sol.countPermutations(arr));      }
}