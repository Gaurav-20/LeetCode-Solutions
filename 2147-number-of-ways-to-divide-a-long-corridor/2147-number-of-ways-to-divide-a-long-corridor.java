class Solution {
    public int numberOfWays(String corridor) {
        int a = 1, b = 0, c = 0, mod = (int) 1e9 + 7;
        for (int it = 0; it < corridor.length(); it++) {
            if (corridor.charAt(it) == 'S') {
                a = (a + c) % mod;
                c = b;
                b = a;
                a = 0;
            } else {
                a = (a + c) % mod;
            }
        }
        return c;
    }
}