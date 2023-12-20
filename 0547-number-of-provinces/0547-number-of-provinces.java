class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int numProvinces = 0;
        int[] visited = new int[n];
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(isConnected, visited, i, n);
                numProvinces++;
            }
        }
        return numProvinces;
    }
    
    void dfs(int[][] isConnected, int[] visited, int node, int n) {
        visited[node] = 1;
        for (int i = 0; i < n; i++) {
            if (i != node && isConnected[node][i] == 1 && visited[i] == 0) {
                dfs(isConnected, visited, i, n);
            }
        }
    }
}