class Solution {
    public int minOperations(int[] nums, int k) {
        int xor = k;
        for (int n : nums) {
            xor ^= n;
        }
        return bits(xor);
    }
    
    public int bits(int n) {
        int cnt = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                cnt += 1;
            }
            n /= 2;
        }
        return cnt;
    }
}