class Pair {
    public int first; // src
    public int second; // dest
    
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Tuple {
    public int first; // stops
    public int second; // node
    public int third; // cost
    
    Tuple(int first, int second, int third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
}

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < flights.length; i++) {
            adj.get(flights[i][0]).add(new Pair(flights[i][1], flights[i][2]));
        }
        Queue<Tuple> queue = new LinkedList<>();
        queue.offer(new Tuple(0, src, 0));
        int[] distance = new int[n];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[src] = 0;
        while (!queue.isEmpty()) {
            Tuple tuple = queue.poll();
            int stops = tuple.first;
            int node = tuple.second;
            int cost = tuple.third;
            if (stops > k) {
                continue;
            }
            for (Pair pair : adj.get(node)) {
                int neighbor = pair.first;
                int edgeCost = pair.second;
                if (cost + edgeCost < distance[neighbor]) {
                    distance[neighbor] = cost + edgeCost;
                    queue.offer(new Tuple(stops + 1, neighbor, cost + edgeCost));
                }
            }
        }
        return (distance[dst] == Integer.MAX_VALUE) ? -1 : distance[dst];
    }
}