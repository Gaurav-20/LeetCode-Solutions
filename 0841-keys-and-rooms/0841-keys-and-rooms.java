class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int numRooms = rooms.size();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numRooms; i++) {
            List<Integer> keys = new ArrayList<>();
            for (Integer key: rooms.get(i)) {
                keys.add(key);
            }
            graph.add(keys);
        }
        boolean[] visited = new boolean[numRooms];
        visited[0] = true;
        for (int i = 0; i < numRooms; i++) {
            if (visited[i] == true) {
                dfs(graph, i, visited);
            }
        }
        for (int i = 0; i < numRooms; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
    
    public void dfs(List<List<Integer>> graph, int node, boolean[] visited) {
        for (Integer room: graph.get(node)) {
            if (visited[room] == false) {
                visited[room] = true;
                dfs(graph, room, visited);
            }
        }
    }
}