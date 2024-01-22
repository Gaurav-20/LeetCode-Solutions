class Solution {
    public int getSum(int a, int b) {
        int sum = 0, carry = 0;
        for (int i = 0; i < 32; i++) {
            int aBit = (a >> i) & 1;
            int bBit = (b >> i) & 1;
            if (carry == 1) {
                if (aBit == bBit) {
                    sum |= (1 << i);
                    if (aBit == 0) {
                        carry = 0;
                    }
                }
            } else {
                if (aBit == bBit) {
                    if (aBit == 1) {
                        carry = 1;
                    }
                } else {
                    sum |= (1 << i);
                }
            }
        }
        return sum;
    }
}