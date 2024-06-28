class Solution {
    public long maximumImportance(int n, int[][] roads) {
        int[] indegree = new int[n];
        for (int[] road : roads) {
            indegree[road[0]] += 1;
            indegree[road[1]] += 1;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return indegree[b] - indegree[a];
        });
        for (int i = 0; i < n; i++) {
            pq.offer(i);
        }
        long result = 0, counter = n;
        while (!pq.isEmpty()) {
            result += indegree[pq.poll()] * counter;
            counter -= 1;
        }
        return result;
    }
}