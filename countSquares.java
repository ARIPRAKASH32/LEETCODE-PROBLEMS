class Solution {
    public int countSquares(int[][] m) {
        int ans=0;
        for(int i=0;i<m.length;i++){
            for(int j=0;j<m[0].length;j++){
                if(m[i][j]>0 && i>0 && j>0){
                    m[i][j]=1+Math.min(m[i-1][j-1],Math.min(m[i-1][j],m[i][j-1]));
                }
                ans+=m[i][j];
            }
        }
        return ans;
    }
}
