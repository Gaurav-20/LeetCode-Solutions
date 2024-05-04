class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n = quiet.length;
        List<List<Integer>> graph = new ArrayList<>();
        // Map<Integer, Integer> loudness = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
            // loudness.put(quiet[i], i);
        }
        for (int[] rich : richer) {
            graph.get(rich[1]).add(rich[0]);
        }
        int[] answer = new int[n];
        for (int person = 0; person < n; person++) {
            // answer[person] = loudness.get(dfs(graph, person, quiet, new boolean[n]));
            answer[person] = dfs(graph, person, quiet, new boolean[n])[1];
        }
        return answer;
    }
    
    public int[] dfs(List<List<Integer>> graph, int person, int[] quiet, boolean[] visited) {
        visited[person] = true;
        int resultLoudness = quiet[person], resultPerson = person;
        for (Integer richerPerson : graph.get(person)) {
            if (!visited[richerPerson]) {
                int[] currResult = dfs(graph, richerPerson, quiet, visited);
                if (currResult[0] < resultLoudness) {
                    resultLoudness = currResult[0];
                    resultPerson = currResult[1];
                }
            }
        }
        return new int[] { resultLoudness, resultPerson };
    }
}