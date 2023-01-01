const int N = 1000000;
int prime[N + 1] = { -1 };

class Solution {
public:
    void precompute() {
        for (int i = 0; i <= N; i++) {
            prime[i] = 1;
        }
        prime[0] = 0;
        prime[1] = 0;
        for (int p = 2; p * p <= N; p++) {
            if (prime[p] == 1) {
                for (int i = p * p; i <= N; i += p) {
                    prime[i] = 0;
                }
            }
        }
    }
    
    vector<int> closestPrimes(int left, int right) {
        if (prime[0] == -1) {
            precompute();
        }
        vector<int> primeNums;
        for (int i = left; i <= right; i++) {
            if (prime[i] == 1) {
                primeNums.push_back(i);
            }
        }
        if (primeNums.size() <= 1) {
            return { -1, -1 };
        }
        vector<int> res = { primeNums[0], primeNums[1] };
        int diff = primeNums[1] - primeNums[0];
        for (int i = 2; i < primeNums.size(); i++) {
            if (diff > primeNums[i] - primeNums[i - 1]) {
                diff = primeNums[i] - primeNums[i - 1];
                res = { primeNums[i - 1], primeNums[i] };
            }
        }
        return res;
    }
};