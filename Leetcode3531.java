class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        int mr [] = new int[n+1];
        int nr [] = new int[n+1];
        int mc [] = new int[n+1];
        int nc [] = new int[n+1];

        Arrays.fill(mr, Integer.MIN_VALUE); 
        Arrays.fill(mc, Integer.MIN_VALUE); 
        Arrays.fill(nr, Integer.MAX_VALUE); 
        Arrays.fill(nc, Integer.MAX_VALUE);
        for(int[] p:buildings){
            int x = p[0];
            int y = p[1];
            mr[y] = Math.max(mr[y],x);
            nr[y] = Math.min(nr[y],x);
            mc[x] = Math.max(mc[x],y);
            nc[x] = Math.min(nc[x],y);
        }
        int c = 0;
        for(int[] p : buildings){
            int x = p[0];
            int y = p[1];
            if (x > nr[y] && x < mr[y] && y > nc[x] && y < mc[x]){
                c++;
            }
        }
        return c;

    }
}
public class Leetcode3531{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] [] buildings = new int[n][2];
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<2 ; j++){
                buildings[i][j] = sc.nextInt();
            }
            
        }
        Solution sol = new Solution();
        System.out.println(sol.countCoveredBuildings(n,buildings));
    }
}