class kthSmallest {
    private int leftK;

    public int kthSmallest(int[][] mat, int k) {
        int low = 0, high = 0;
        for (int[] row : mat) {
            low += row[0];
            high += row[row.length - 1];
        }
        int min = low;
        low -= 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            leftK = k;
            if (dfs(mat, mat.length - 1, mid - min)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    private boolean dfs(int[][] mat, int i, int s) {
        if (i < 0) return --leftK == 0;
        for (int val : mat[i]) {
            if (val - mat[i][0] > s) break;
            if (dfs(mat, i - 1, s - (val - mat[i][0]))) return true;
        }
        return false;
    }
}

