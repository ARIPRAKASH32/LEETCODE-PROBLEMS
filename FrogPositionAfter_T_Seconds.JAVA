class FrogPositionAfter_T_Seconds {
    LinkedList<Integer> adjListArray[];
    public double frogPosition(int n, int[][] edges, int t, int target) {
        if (n == 1) return 1.0;
        adjListArray = new LinkedList[n + 1];
        for(int i = 0; i <= n ; i++) adjListArray[i] = new LinkedList<>();
        for (int[] edge : edges) {
            adjListArray[edge[0]].add(edge[1]);
            adjListArray[edge[1]].add(edge[0]);
        }

        return dfs(1, t, target, new boolean[n + 1]);
    }

    private double dfs(int node, int t, int target, boolean[] visited) {
        if (node != 1 && adjListArray[node].size() == 1 || t == 0) {
            if (node == target)
                return 1;
            else return 0;
        }
        visited[node] = true;
        double res = 0.0;
        for (int child : adjListArray[node]) {
            if (visited[child]) continue; // skip visited children
            res += dfs(child, t - 1, target, visited);
        }
        if (node != 1)
            return res * 1.0 / (adjListArray[node].size() - 1);
        else
            return res * 1.0 / (adjListArray[node].size());
    }
}