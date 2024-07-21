class Solution {
    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        int[][] result = new int[k][k];
        List<Integer> row = check(rowConditions, k);
        List<Integer> col = check(colConditions, k);
        if (!(row.size() > 0 && col.size() > 0)) {
            return new int[0][0];
        }
        Map<Integer, Integer> rowMap = new HashMap<>();
        Map<Integer, Integer> colMap = new HashMap<>();
        for (int i = 0; i < row.size(); i++) {
            rowMap.put(row.get(i), i);
        }
        for (int i = 0; i < col.size(); i++) {
            colMap.put(col.get(i), i);
        }
        for (int i = 1; i <= k; i++) {
            result[rowMap.get(i)][colMap.get(i)] = i;
        }
        return result;
    }
    
    public List<Integer> topologicalSort(int V, Map<Integer, List<Integer>> adj) {
        int[] indegree = new int[V];
        for (int u = 1; u < V; u++) {
            for (Integer neigh: adj.getOrDefault(u, new ArrayList<>())) {
                indegree[neigh] += 1;
            }
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i < V; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }
        int cnt = 0;
        List<Integer> topOrder = new ArrayList<>();
        while (!queue.isEmpty()) {
            int u = queue.poll();
            topOrder.add(u);
            for (Integer neigh: adj.getOrDefault(u, new ArrayList<>())) {
                indegree[neigh] -= 1;
                if (indegree[neigh] == 0) {
                    queue.offer(neigh);
                }
            }
            cnt += 1;
        }
        if (cnt != V - 1) {
            return new ArrayList<>();
        }
        return topOrder;
    }
    
    public List<Integer> check(int[][] arr, int k) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            int src = arr[i][0], dest = arr[i][1];
            if (adj.get(src) == null) {
                adj.put(src, new ArrayList<>());
            }
            adj.get(src).add(dest);
        }
        return topologicalSort(k + 1, adj);
    }
}