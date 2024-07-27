class Solution {
    public int minChanges(int n, int k) {
        int changes = 0;
        for (int i = 0; i < 32; i++) {
            if (n == k) {
                break;
            }
            if (n % 2 != k % 2) {
                if (n % 2 == 0) {
                    return -1;
                } else {
                    changes += 1;
                }
            }
            n /= 2;
            k /= 2;
        }
        return changes;
    }
}