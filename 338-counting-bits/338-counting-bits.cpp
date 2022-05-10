class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int quotient = i >> 1;
            int remainder = i % 2;
            res[i] = res[quotient] + remainder;
        }
        return res;
    }
};