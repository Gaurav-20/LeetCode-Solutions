class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n = quiet.length;
        List<List<Integer>> graph = new ArrayList<>();
        Map<Integer, Integer> loudness = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
            loudness.put(quiet[i], i);
        }
        for (int[] rich : richer) {
            graph.get(rich[1]).add(rich[0]);
        }
        int[] answer = new int[n];
        for (int person = 0; person < n; person++) {
            answer[person] = loudness.get(dfs(graph, person, quiet, new boolean[n]));
        }
        return answer;
    }
    
    public int dfs(List<List<Integer>> graph, int person, int[] quiet, boolean[] visited) {
        visited[person] = true;
        int result = quiet[person];
        for (Integer richerPerson : graph.get(person)) {
            if (!visited[richerPerson]) {
                result = Math.min(result,
                                  Math.min(quiet[richerPerson],
                                           dfs(graph, richerPerson, quiet, visited)));
            }
        }
        return result;
    }
}