class Solution {
    public int findCenter(int[][] edges) {
        int n = edges.length + 1;
        int[] freq = new int[n + 1];
        for (int[] edge : edges) {
            freq[edge[0]] += 1;
            freq[edge[1]] += 1;
            if (freq[edge[0]] == n - 1) {
                return edge[0];
            }
            if (freq[edge[1]] == n - 1) {
                return edge[1];
            }
        }
        return -1;
    }
}