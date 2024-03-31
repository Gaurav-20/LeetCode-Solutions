class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1 || edges.length == 0) {
            return Arrays.asList(0);
        }
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] degree = new int[n];
        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                queue.add(i);
            }
        }
        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            int size = queue.size();
            result = new ArrayList<>();
            while (size-- > 0) {
                Integer node = queue.poll();
                result.add(node);
                for (Integer neigh : adj.get(node)) {
                    degree[neigh] -= 1;
                    if (degree[neigh] == 1)
                        queue.add(neigh);
                }
            }
        }
        return result;
    }
}