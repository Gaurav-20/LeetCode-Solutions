class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int low = 1, high = Arrays.stream(position).max().getAsInt();
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (possible(position, mid, m)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (possible(position, high, m)) {
            return high;
        }
        if (possible(position, low, m)) {
            return low;
        }
        return -1;
    }
    
    public boolean possible(int[] position, int mid, int m) {
        int count = 1, curr = position[0];
        for (int i = 1; i < position.length; i++) {
            if (position[i] - curr >= mid) {
                curr = position[i];
                count += 1;
            }
        }
        return count >= m;
    }
}