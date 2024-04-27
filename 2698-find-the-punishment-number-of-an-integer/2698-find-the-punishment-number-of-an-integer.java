class Solution {
    public int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (isPunishable(i)) {
                result += i * i;
            }
        }
        return result;
    }
    
    public boolean isPunishable(int n) {
        String str = String.valueOf(n * n);
        return isPartitioningPossible(str, 0, 0, 0, n);
    }
    
    public boolean isPartitioningPossible(String s, int idx, int sum, int curr, int n) {
        if (idx >= s.length()) {
            return sum + curr == n;
        }
        int currDigit = s.charAt(idx) - '0';
        return isPartitioningPossible(s, idx + 1, sum, curr * 10 + currDigit, n)
            || isPartitioningPossible(s, idx + 1, sum + curr, currDigit, n);
    }
}