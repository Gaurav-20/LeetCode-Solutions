class Solution {
    public int largestAltitude(int[] gain) {
        int result = Math.max(0, gain[0]);
        for (int i = 1; i < gain.length; i++) {
            gain[i] += gain[i - 1];
            result = Math.max(result, gain[i]);
        }
        return result;
    }
}