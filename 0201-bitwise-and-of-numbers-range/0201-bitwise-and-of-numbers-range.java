class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        if (left == 0 || left == right) {
            return left;
        }
        long n = 0, result = Integer.MAX_VALUE;
        while (n < 31) {
            if (belongsToRange(1 << n, left, right) && 
                belongsToRange((1 << n) - 1, left, right)) {
                result = 0;
                break;
            }
            n++;
        }
        if (result == 0) {
            return (int) result;
        }
        result = left;
        for (long i = left + 1; i <= right; i++) {
            result &= i;
        }
        return (int) result;
    }
    
    public boolean belongsToRange(int num, int left, int right) {
        return (left <= num) && (right >= num);
    }
}