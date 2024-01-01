class Solution {
    private int count = 0;
    private Map<Integer, Boolean>[] adj;

    private void dfs(int city, int parent) {
        for (Integer nbr : adj[city].keySet()) {
            Boolean needReorder = adj[city].get(nbr);
            if (nbr != parent) {
                if (needReorder) {
                    count++;
                }
                dfs(nbr, city);
            }
        }
    }

    public int minReorder(int n, int[][] connections) {
        adj = new HashMap[n];
        Arrays.setAll(adj, map -> new HashMap<>());

        for (int[] conn : connections) {
            adj[conn[0]].put(conn[1], true);
            adj[conn[1]].put(conn[0], false);
        }
        dfs(0, -1);
        return count;
    }
}