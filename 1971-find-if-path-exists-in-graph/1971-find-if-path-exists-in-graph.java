class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        boolean[] visited = new boolean[n];
        dfs(adj, source, visited);
        return visited[destination];
    }
    
    public void dfs(List<List<Integer>> adj, int src, boolean[] visited) {
        visited[src] = true;
        for (Integer neigh : adj.get(src)) {
            if (!visited[neigh]) {
                dfs(adj, neigh, visited);
            }
        }
    }
}