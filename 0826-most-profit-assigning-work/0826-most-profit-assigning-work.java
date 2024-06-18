class Job {

    int difficulty;
    int profit;

    public Job(int difficulty, int profit) {
        this.difficulty = difficulty;
        this.profit = profit;
    }
}

class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        List<Job> jobs = new ArrayList<>();
        int n = difficulty.length;

        for (int i = 0; i < n; i++) {
            Job job = new Job(difficulty[i], profit[i]);
            jobs.add(job);
        }
        
        Collections.sort(jobs, (a, b) -> a.difficulty - b.difficulty);
        Arrays.sort(worker);

        int result = 0, j = 0, m = worker.length, maxProfit = 0;

        for (int i = 0; i < m; i++) {
            while (j < n && jobs.get(j).difficulty <= worker[i]) {
                maxProfit = Math.max(maxProfit, jobs.get(j).profit);
                j++;
            } 
            result += maxProfit;
        }
        return result;
    }
}