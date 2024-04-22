class Solution {
    public int kthGrammar(int n, int k) {
        return bitCount(k - 1) % 2;
    }
    
    public int bitCount(int n) {
        int bits = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                bits += 1;
            }
            n /= 2;
        }
        return bits;
    }
}