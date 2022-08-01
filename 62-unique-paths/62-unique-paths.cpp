class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n == 1 || m == 1) {
            return 1;
        }
        long long res = 1;
        int j = 1;
        for (int i = m; i <= m + n - 2; i++, j++) {       
            // Instead of taking factorial, keep on multiply & divide
            res = (res * i) / j;
        }
        return (int)res;
    }
};