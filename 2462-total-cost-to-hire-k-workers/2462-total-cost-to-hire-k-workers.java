class WorkerComparator implements Comparator<Pair<Integer, Integer>> {
    public int compare(Pair<Integer, Integer> w1, Pair<Integer, Integer> w2) {
        if (w1.getKey() == w2.getKey()) {
            return w1.getValue() - w2.getValue();
        }
        return w1.getKey() - w2.getKey();
    }
}

class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        // Range covers the entire array space, just sort and sum the first k elements
        if (candidates * 2 >= costs.length) {
            Arrays.sort(costs);
            long sum = 0;
            for(int i = 0; i < k; i++) {
                sum += costs[i];
            }
            return sum;
        }
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<Pair<Integer, Integer>>(new WorkerComparator());

        int i = 0;
        int j = costs.length - 1;
        
        // Add the initial range of workers from both ends of array
        // Pair(cost, index)
        for (int m = 0; m < candidates; m++) {
            pq.offer(new Pair(costs[m], m));
            pq.offer(new Pair(costs[j - m], j - m));
        }

        // Keep pointers i and j to add the next workers
        long hiringCost = 0;
        i = i + candidates - 1;
        j = j - candidates + 1;
        
        while (k > 0) {
            Pair<Integer, Integer> worker = pq.poll();
            int workerCost = worker.getKey();
            int workerPosition = worker.getValue();

            if (workerPosition <= i) {
                // The worker we pulled out is from the left side
                if (i < j - 1) {
                    // i and j are already right next to each other
                    // This means we already added all elements in the array into the pq
                    i++;
                    pq.offer(new Pair(costs[i], i));
                }
            } else {
                // The worker we pulled is from the right side
                if (j > i + 1) {
                    // i and j are already right next to each other
                    // This means we already added all elements in the array into the pq
                    j--;
                    pq.offer(new Pair(costs[j], j));
                }
            }
            k--;
            hiringCost += workerCost;
        }
        return hiringCost;
    }
}