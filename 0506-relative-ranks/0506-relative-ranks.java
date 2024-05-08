class Pair {
    public int first;
    public int second;
    
    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        String[] result = new String[n];
        PriorityQueue<Pair> pq = new PriorityQueue(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                return p2.first - p1.first;
            }
        });
        for (int i = 0; i < n; i++) {
            pq.offer(new Pair(score[i], i));
        }
        int counter = 1;
        for (int i = 0; i < n; i++) {
            int index = pq.peek().second;
            if (counter == 1) {
                result[index] = "Gold Medal";
            } else if (counter == 2) {
                result[index] = "Silver Medal";
            } else if (counter == 3) {
                result[index] = "Bronze Medal";
            } else {
                result[index] = String.valueOf(counter);
            }
            pq.poll();
            counter += 1;
        }
        return result;
    }
}