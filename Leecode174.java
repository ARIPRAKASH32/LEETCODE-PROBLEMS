import java.util.*;
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
      
        int m = dungeon.length;
        int n = dungeon[0].length;
        int [][] dp = new int[m][n];
        
        for(int i = m-1 ; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                
                if(i == m-1 && j==n-1){
                    dp[i][j] = Math.max(1,1 - dungeon[i][j]);
                }
                else if(i == m-1){
                    dp[i][j] = Math.max(1, dp[i][j+1] - dungeon[i][j]);
                }
                else if(j == n-1){
                    dp[i][j] = Math.max(1, dp[i+1][j] - dungeon[i][j]);
                }
                else{
                    int need = Math.min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                    dp[i][j] = Math.max(1, need);
                }
            }
        }
        return dp[0][0];
    }
}
public class Leecode174{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int low = sc.nextInt();
		int low1 = sc.nextInt();
		int [][] arr = new int[low][low1];
		for(int i=0 ; i<low ; i++){
			for(int j =0 ; j<low1 ; j++){
				arr[i][j]=sc.nextInt();
			}
		}		
		Solution sol = new Solution();
		System.out.println(sol.calculateMinimumHP(arr));
	}
}