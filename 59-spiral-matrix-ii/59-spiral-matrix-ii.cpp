class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int val = 1;
        int lb = 0, rb = n - 1; 
        int tb = 0, bb = n - 1;
        while (lb <= rb && tb <= bb) {
            for (int i = lb; i <= rb; i++) {
                res[tb][i] = val++;
            }
            tb++;
            for (int i = tb; i <= bb; i++) {
                res[i][rb] = val++;
            }
            rb--;
            for (int i = rb; i >= lb; i--) {
                res[bb][i] = val++; 
            }
            bb--;
            for (int i = bb; i >= tb; i--) {
                res[i][lb] = val++;
            }
            lb++;
        }
        return res;
    }
};