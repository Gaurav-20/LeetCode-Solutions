class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int i = 0; i < numCourses; i++) {
            adj.put(i, new ArrayList<>());
        }
        int[] indegree = new int[numCourses];
        for (int[] pre : prerequisites) {
            adj.get(pre[1]).add(pre[0]);
            indegree[pre[0]] += 1;
        }
        Queue<Integer> queue = new LinkedList<>();
        int canBeCompletedCount = 0;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
                canBeCompletedCount += 1;
            }
        }
        while (!queue.isEmpty()) {
            Integer node = queue.poll();
            for (Integer neigh : adj.get(node)) {
                indegree[neigh] -= 1;
                if (indegree[neigh] == 0) {
                    queue.add(neigh);
                    canBeCompletedCount += 1;
                }
            }
        }
        return canBeCompletedCount == numCourses;
    }
}