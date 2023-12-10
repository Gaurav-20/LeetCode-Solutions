class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1, high = 0;
        for (int i = 0; i < piles.length; i++) {
            high = Math.max(high, piles[i]);
        }
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (isPossibleToEatAllBananas(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (isPossibleToEatAllBananas(piles, low, h)) {
            return low;
        }
        return high;
    }
    
    public boolean isPossibleToEatAllBananas(int[] piles, int speed, int hoursAvailable) {
        int hoursNeeded = 0;
        for (int i = 0; i < piles.length; i++) {
            hoursNeeded += (piles[i] / speed);
            if (piles[i] % speed != 0) {
                hoursNeeded += 1;
            }
        }
        return hoursNeeded <= hoursAvailable;
    }
}