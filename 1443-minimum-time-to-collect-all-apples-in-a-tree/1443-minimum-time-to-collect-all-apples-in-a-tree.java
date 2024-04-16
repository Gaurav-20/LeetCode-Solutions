class Solution {
    public boolean[] visited;
    
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        List<List<Integer>> list = new ArrayList<>(n);
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            list.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            list.get(edge[0]).add(edge[1]);
            list.get(edge[1]).add(edge[0]);
        }
        return Math.max((dfs(list, 0, hasApple) - 1) * 2, 0);
    }
    
    public int dfs(List<List<Integer>> list, int node, List<Boolean> hasApple) {
        if (visited[node]) {
            return 0;
        }
        visited[node] = true;
        int cost = 0;
        for (Integer neigh : list.get(node)) {
            cost += dfs(list, neigh, hasApple);
        }
        if (hasApple.get(node) == false && cost == 0) {
            return 0;
        }
        return cost + 1;
    }
}