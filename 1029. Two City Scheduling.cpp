class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int totalCost = 0;
        int n = costs.length / 2;

        Arrays.sort(costs, (a,b) -> Integer.compare(a[0]-a[1], b[0] - b[1]));

        for(int i = 0; i < n; i++){
            totalCost += costs[i][0];
        }

        for(int i = n; i < n * 2; i++){
            totalCost += costs[i][1];
        }
        return totalCost;
    }
}
