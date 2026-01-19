class Solution {

    public int f(int i, int j, int[][] arr, int[][] dp) {

        if (i == arr.length - 1)
            return arr[i][j];

        if (dp[i][j] != Integer.MAX_VALUE)
            return dp[i][j];

        int best = Integer.MAX_VALUE;

        for (int k = 0; k < arr[0].length; k++) {
            if (k == j) continue; // can't pick same column

            best = Math.min(best, f(i+1, k, arr, dp));
        }

        return dp[i][j] = arr[i][j] + best;
    }

    public int minFallingPathSum(int[][] matrix) {

        int n = matrix.length;
        int m = matrix[0].length;

        int[][] dp = new int[n][m];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);

        int ans = Integer.MAX_VALUE;

        for (int j = 0; j < m; j++) {
            ans = Math.min(ans, f(0, j, matrix, dp));
        }

        return ans;
    }
}