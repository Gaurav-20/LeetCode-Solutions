class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][] workers = new double[n][2];

        for (int i = 0; i < n; i++) {
            workers[i] = new double[] { (double) wage[i] / quality[i], (double) quality[i] };
        }

        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        
        PriorityQueue<Double> pq = new PriorityQueue<>((a, b) -> Double.compare(b, a));
        double sum = 0;
        double result = Double.MAX_VALUE;
        
        for (double[] worker : workers) {
            sum += worker[1];
            pq.add(worker[1]);
            if (pq.size() > k) {
                sum -= pq.poll();
            }
            if (pq.size() == k) {
                result = Math.min(result, sum * worker[0]);
            }
        }
        return result;
    }
}