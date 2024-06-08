class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] parent = new int[n];
        Arrays.fill(parent, 1);
        for (int i = 0; i < edges.length; i++) {
            parent[edges[i][1]] = 0;
        }
        int result = -1;
        for (int i =  0; i < n; i++) {
            if (parent[i] == 1) {
                if (result == -1) {
                    result = i;
                } else {
                    result = -1;
                    break;
                }
            }
        }
        return result;
    }
}