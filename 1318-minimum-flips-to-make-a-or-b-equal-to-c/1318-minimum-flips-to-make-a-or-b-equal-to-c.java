class Solution {
    public int minFlips(int a, int b, int c) {
        int result = 0;
        // 32 bits is enough as per the given ranges
        for (int i = 0; i < 32; i++) {
            int lastBitOfA = a & 1;
            int lastBitOfB = b & 1;
            int lastBitOfC = c & 1;
            if (lastBitOfC == 1) {
                if (lastBitOfA == 0 && lastBitOfB == 0) {
                    result++;
                }
            } else {
                if (lastBitOfA == 1) {
                    result++;
                }
                if (lastBitOfB == 1) {
                    result++;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return result;
    }
}