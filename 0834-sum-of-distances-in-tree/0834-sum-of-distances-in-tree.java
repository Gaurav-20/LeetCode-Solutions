class Solution {
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        Map<Integer, List<Integer>> tree = new HashMap<>();
        for (int i = 0; i < n; i++) {
            tree.put(i, new ArrayList<>());
        }
        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }
        int[] countArr = new int[n];
        getCountArr(tree, 0, countArr, new boolean[n]);
        int[] sumOfDistances = new int[n];
        sumOfDistances[0] = getRootDistance(tree, 0, countArr, new boolean[n]);
        findAllDistances(tree, 0, countArr, sumOfDistances, new boolean[n]);
        return sumOfDistances;
    }
    
    public int getCountArr(Map<Integer, List<Integer>> tree, int src, int[] countArr, boolean[] visited) {
        visited[src] = true;
        int ct = 1;
        for (int nbr : tree.get(src)) {
            if (!visited[nbr]) {
                ct += getCountArr(tree, nbr, countArr, visited);
            }
        }
        return countArr[src] = ct;
    }
    
    public int getRootDistance(Map<Integer, List<Integer>> tree, int src, int[] countArr, boolean[] visited) {
        int dist = 0;
        visited[src] = true;
        for (int nbr : tree.get(src)) {
            if (!visited[nbr]) {
                dist += countArr[nbr] + getRootDistance(tree, nbr, countArr, visited);
            }
        }
        return dist;
    }
    
    public void findAllDistances(Map<Integer, List<Integer>> tree, int src, int[] countArr, int[] sumOfDistances, boolean[] visited) {
        visited[src] = true;
        for (int nbr : tree.get(src)) {
            if (!visited[nbr]) {
                sumOfDistances[nbr] = sumOfDistances[src] + tree.size() - (2 * countArr[nbr]);
                findAllDistances(tree, nbr, countArr, sumOfDistances, visited);
            }
        }
    }
}