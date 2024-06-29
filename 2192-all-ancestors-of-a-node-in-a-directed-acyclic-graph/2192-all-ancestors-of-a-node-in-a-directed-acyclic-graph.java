class Solution {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> result = new ArrayList<>();
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge: edges) {
            int from = edge[0];
            int to = edge[1];
            graph.computeIfAbsent(to, k -> new ArrayList<>()).add(from);
        }
        for (int node = 0; node < n; node++) { 
            List<Integer> list = new ArrayList<>();
            dfs(graph, node, new boolean[n], list);
            Collections.sort(list);
            result.add(list);
        }
        return result;
    }
    
    public void dfs(Map<Integer, List<Integer>> graph, int node, boolean[] visited, List<Integer> list) {
        visited[node] = true;
        for (Integer child: graph.getOrDefault(node, new ArrayList<>())) {
            if (!visited[child]) {
                visited[child] = true;
                dfs(graph, child, visited, list);
                list.add(child);
            }
        }
    }
}