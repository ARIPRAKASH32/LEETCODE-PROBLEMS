class calcEq
uation {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        // Step 1: Build the graph
        Map<String, Map<String, Double>> graph = new HashMap<>();
        
        for (int i = 0; i < equations.size(); i++) {
            String u = equations.get(i).get(0);
            String v = equations.get(i).get(1);
            double val = values[i];
            
            graph.putIfAbsent(u, new HashMap<>());
            graph.putIfAbsent(v, new HashMap<>());
            
            graph.get(u).put(v, val);
            graph.get(v).put(u, 1.0 / val);
        }

        // Step 2: Process queries
        double[] results = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            String start = queries.get(i).get(0);
            String end = queries.get(i).get(1);
            Set<String> visited = new HashSet<>();
            results[i] = dfs(start, end, graph, visited);
        }

        return results;
    }

    private double dfs(String curr, String target, Map<String, Map<String, Double>> graph, Set<String> visited) {
        if (!graph.containsKey(curr) || !graph.containsKey(target)) {
            return -1.0;
        }
        if (curr.equals(target)) return 1.0;

        visited.add(curr);

        for (Map.Entry<String, Double> neighbor : graph.get(curr).entrySet()) {
            String next = neighbor.getKey();
            double weight = neighbor.getValue();

            if (!visited.contains(next)) {
                double result = dfs(next, target, graph, visited);
                if (result != -1.0) {
                    return weight * result;
                }
            }
        }

        return -1.0;
    }
}