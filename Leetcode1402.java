class Solution {
    public int maxSatisfaction(int[] satisfaction) {
         Arrays.sort(satisfaction);
        int n = satisfaction.length;
        int presum = 0, res = 0;
        for (int i = n - 1; i >= 0; i--) {
            presum += satisfaction[i];
            if (presum < 0) {
                break;
            }
            res += presum;
        }
        return res;
    }
}
public class Leetcode1402{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] ar = new int [n];
        for(int i=0 ; i<n ; i++){
            ar[i] = sc.nextInt();
        }
        Solution sol = new Solution();
        System.out.println(sol.maxSatisfaction(ar));
    }
}
