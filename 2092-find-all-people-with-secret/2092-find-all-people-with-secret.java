class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        Set<Integer> result = new HashSet<>();

        int[] timeknown = new int[n];
        Arrays.fill(timeknown, Integer.MAX_VALUE);

        timeknown[0] = 0;
        timeknown[firstPerson] = 0;
        
        Map<Integer, List<int[]>> adj = new HashMap<>();
        
        for (int[] it : meetings) {
            adj.computeIfAbsent(it[0], k -> new ArrayList<>()).add(new int[]{it[1], it[2]});
            adj.computeIfAbsent(it[1], k -> new ArrayList<>()).add(new int[]{it[0], it[2]});
        }

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(firstPerson);
        queue.offer(0);
        result.add(firstPerson);
        result.add(0);

        while (!queue.isEmpty()){
            int curr = queue.poll();
            for (int[] it : adj.getOrDefault(curr, new ArrayList<>())) {
                if (it[1] >= timeknown[curr] && timeknown[it[0]] > it[1]) {
                    timeknown[it[0]] = it[1];
                    result.add(it[0]);
                    queue.offer(it[0]);
                }
            }
        }

        return new ArrayList<>(result);
    }
}