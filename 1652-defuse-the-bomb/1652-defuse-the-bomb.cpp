class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0) {
            return res;
        }
        bool neg = k < 0;
        k = abs(k);
        for (int i = 0; i < n; i++) {
            int it = i, sum = 0;
            for (int c = 0; c < k; c++) {
                it = neg ? (it - 1 + n) % n : (it + 1) % n;
                sum += code[it];    
            }
            res[i] = sum;
        }
        return res;
    }
};