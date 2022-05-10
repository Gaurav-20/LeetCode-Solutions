class Solution {
public:
    void solve(int a, int b, int i, int& sum, int& carry) {
        if (carry) {
            if (a == b) {
                if (a == 0) {
                    sum |= (1 << i);
                    carry = 0;
                } else {
                    sum |= (1 << i);
                }
            }
        } else {
            if (a == b) {
                if (a == 1) {
                    carry = 1;
                }
            } else {
                sum |= (1 << i);
            }
        }
    }
    
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int aBit = (a >> i) & 1;
            int bBit = (b >> i) & 1;
            solve(aBit, bBit, i, sum, carry);
        }
        return sum;
    }
};