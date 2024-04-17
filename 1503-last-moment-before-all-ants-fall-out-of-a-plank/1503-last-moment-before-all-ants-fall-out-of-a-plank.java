class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int result = 0;
        for (int ant : left) {
            result = Math.max(result, ant);
        }
        for (int ant : right) {
            result = Math.max(result, n - ant);
        }
        return result;
    }
}