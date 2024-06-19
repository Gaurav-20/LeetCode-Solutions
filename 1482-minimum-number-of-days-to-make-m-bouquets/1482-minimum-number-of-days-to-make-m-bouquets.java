class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if (m * k > bloomDay.length) {
            return -1;
        }
        int low = 1, high = Arrays.stream(bloomDay).max().getAsInt();
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, mid, m, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (canMake(bloomDay, low, m, k)) {
            return low;
        }
        if (canMake(bloomDay, high, m, k)) {
            return high;
        }
        return -1;
    }
    
    public boolean canMake(int[] bloomDay, int mid, int m, int k) {
        int counter = 0, bouquets = 0;
        for (int i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= mid) {
                counter += 1;
            } else {
                counter = 0;
            }
            if (counter == k) {
                bouquets += 1;
                counter = 0;
            }
        }
        return bouquets >= m;
    }
}