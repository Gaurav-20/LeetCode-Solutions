class Solution {
public:
    vector<int> buildSeive(int n) {
        vector<int> isPrime(n + 1, true);
        isPrime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        return isPrime;
    }
    
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> isPrime = buildSeive(n);
        vector<vector<int>> res;
        for (int i = 2; i < n; i++) {
            if (isPrime[i] && isPrime[n - i] && i <= n - i) {
                res.push_back({ i, n - i });
            }
        }
        return res;
    }
};