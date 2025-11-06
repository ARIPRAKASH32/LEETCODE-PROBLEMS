class longestIncreasingPath {
    int[][] directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // All the allowed four directions
    
    public int recursion(int[][] matrix, int i, int j, int n, int m, int[][] dp){
        if(dp[i][j] != -1){ // if this case is already evaluated
            return dp[i][j]; // directly return it
        }

        dp[i][j] = 1; // curr position is itself a path of length 1

        for(int[] dir : directions){
            // explore all the four directions
            int x = i + dir[0];
            int y = j + dir[1];

            if(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j]){
                // move iff, you are inside bound and the next position have element > curr element
                dp[i][j] = Math.max(dp[i][j], 1 + recursion(matrix, x, y, n, m, dp)); // store the max path length
            }
        }
        // Return the longest increasing path starting from cell (i, j)
        return dp[i][j];
    }

    public int longestIncreasingPath(int[][] matrix) {
        // DP Approach using Memoization

        if(matrix.length == 0) return 0; // edge case
        int longestPath = 0; // our ans
        int n = matrix.length;
        int m = matrix[0].length;

        int[][] dp = new int[n][m]; // for memoization

        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], -1);
        }

        // For each cell, compute the longest increasing path starting from it
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int path  = recursion(matrix, i, j, n, m, dp);
                longestPath = Math.max(longestPath, path); // update the global longest path
            }
        }
        // Return the overall longest increasing path length
        return longestPath;
    }
}