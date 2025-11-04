import java.util.*;

class subtree {

    private int solve(int subtree, int[][] dist, int n) {
        int cntN = 0, cntE = 0, mxd = 0;

        for (int i = 0; i < n; i++) {
            if (((subtree >> i) & 1) == 0) continue;

            cntN++;
            for (int j = i + 1; j < n; j++) {
                if (((subtree >> j) & 1) == 0) continue;

                if (dist[i][j] == 1) {
                    cntE++;
                }
                mxd = Math.max(mxd, dist[i][j]);
            }
        }

        if (cntN == cntE + 1) {
            return mxd;
        }

        return -1;
    }

    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
        int[] result = new int[n - 1];
        int[][] dist = new int[15][15];

        // Initialize distance array
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Populate direct distances based on edges
        for (int[] edge : edges) {
            dist[edge[0] - 1][edge[1] - 1] = 1;
            dist[edge[1] - 1][edge[0] - 1] = 1;
        }

        // Floyd-Warshall to compute shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != Integer.MAX_VALUE && dist[j][k] != Integer.MAX_VALUE) {
                        dist[i][j] = dist[j][i] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Iterate over all subsets of nodes
        for (int i = 0; i < (1 << n); i++) {
            int ans = solve(i, dist, n);
            if (ans > 0) {
                result[ans - 1]++;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 4;
        int[][] edges = {{1, 2}, {2, 3}, {2, 4}};
        int[] result = solution.countSubgraphsForEachDiameter(n, edges);
        System.out.println(Arrays.toString(result));
    }
}