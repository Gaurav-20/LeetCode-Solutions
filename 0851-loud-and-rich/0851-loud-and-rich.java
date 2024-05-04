class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n = quiet.length;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] rich : richer) {
            graph.get(rich[1]).add(rich[0]);
        }
        int[] answer = new int[n];
        for (int person = 0; person < n; person++) {
            answer[person] = bfs(graph, person, quiet, n);
        }
        return answer;
    }
    
    public int bfs(List<List<Integer>> graph, int person, int[] quiet, int n) {
        int resultPerson = person, resultLoudness = quiet[person];
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(person);
        visited[person] = true;
        while (!queue.isEmpty()) {
            Integer currPerson = queue.poll();
            if (quiet[currPerson] < resultLoudness) {
                resultLoudness = quiet[currPerson];
                resultPerson = currPerson;
            }
            for (Integer richerPerson : graph.get(currPerson)) {
                if (!visited[richerPerson]) {
                    visited[richerPerson] = true;
                    queue.offer(richerPerson);
                }
            }
        }
        return resultPerson;
    }
}