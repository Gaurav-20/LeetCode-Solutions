class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length, m = potions.length;
        Arrays.sort(potions);
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = findNumberOfSuccessfulPotions(spells[i], potions, success, m);
        }
        return result;
    }
    
    public int findNumberOfSuccessfulPotions(int spell, int[] potions, long success, int m) {
        int low = 0, high = m - 1;
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if ((long) potions[mid] * (long) spell >= success) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if ((long) potions[low] * (long) spell >= success) {
            return m - low;
        } else if ((long) potions[high] * (long) spell >= success) {
            return m - high;
        } else {
            return 0;
        }
    }
}