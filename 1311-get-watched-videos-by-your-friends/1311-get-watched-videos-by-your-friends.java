class Solution {
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        int n = watchedVideos.size();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            for (int f : friends[i]) {
                graph.get(i).add(f);
            }
        }
        
        Map<String, Integer> map = new HashMap<>();
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        visited[id] = true;
        queue.offer(id);
        int currLevel = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                Integer curr = queue.poll();
                if (currLevel == level) {
                    for (String video : watchedVideos.get(curr)) {
                        map.put(video, map.getOrDefault(video, 0) + 1);
                    }
                }
                for (Integer neigh : graph.get(curr)) {
                    if (!visited[neigh]) {
                        visited[neigh] = true;
                        queue.offer(neigh);
                    }
                }
            }
            currLevel += 1;
        }
        List<String> result = new ArrayList<>(map.keySet());
        Collections.sort(result, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                int freq1 = map.get(s1), freq2 = map.get(s2);
                if (freq1 == freq2) {
                    return s1.compareTo(s2);
                } else {
                    return freq1 - freq2;
                }
            }
        });
        return result;
    }
}