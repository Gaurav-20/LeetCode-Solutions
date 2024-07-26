class Solution {    
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int total = Integer.MAX_VALUE, result = 0;
        Map<Integer, List<int[]>> map = new HashMap<>();
        for (int[] edge: edges) {
            if (!map.containsKey(edge[0])) {
                map.put(edge[0], new ArrayList<>());
            }
            if (!map.containsKey(edge[1])) {
                map.put(edge[1], new ArrayList<>());
            }
            map.get(edge[0]).add(new int[] { edge[1], edge[2] });
            map.get(edge[1]).add(new int[] { edge[0], edge[2] });  
        }
        for (int i = n - 1; i >= 0; i--) {
            int[] dist = new int[n];
            Arrays.fill(dist, Integer.MAX_VALUE);
            dist[i] = 0;
            PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
            pq.add(new int[] { i, 0 });

            while (!pq.isEmpty()) {
                int[] a = pq.poll();
                List<int[]> list = map.get(a[0]);
                if (list != null && list.size() > 0) {
                    for (int[]temp: list) {
                        if (dist[temp[0]] > a[1] + temp[1]) {
                            dist[temp[0]] = a[1] + temp[1];
                            pq.add(new int[]{ temp[0], dist[temp[0]] });
                        }
                    }
                }
            }
            int count = 0;
            for (int k = 0; k < n; k++) {
                if (dist[k] <= distanceThreshold) {
                    count += 1;
                }
            }
            if (count < total) {
                result = i;
                total = Math.min(total, count);
            }
        }
        return result;
    }
}