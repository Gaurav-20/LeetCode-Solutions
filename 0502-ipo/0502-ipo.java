class Pair {
    public int first;
    public int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        List<Pair> projects = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            projects.add(new Pair(capital[i], profits[i]));
        }
        Collections.sort(projects, Comparator.comparingInt(p -> p.first));
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int i = 0;
        while (k-- > 0) {
            while (i < n && projects.get(i).first <= w) {
                maxHeap.add(projects.get(i).second);
                i++;
            }
            if (maxHeap.size() == 0) {
                break;
            }
            w += maxHeap.poll();
        }
        return w;
    }
}