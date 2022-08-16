#define NMAX 5000001
bool isPrime[NMAX];
int cnt[NMAX];

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        if (!isPrime[2]) {
            memset(isPrime, true, sizeof(isPrime));
            for (int i = 2; i < NMAX; i++) {
                if (!isPrime[i]) {
                    continue;
                }
                for (int j = i * 2; j < NMAX; j += i) {
                    isPrime[j] = false;
                }
            }
            for (int i = 3; i < NMAX; i++) {
                cnt[i] = (isPrime[i - 1]) + cnt[i - 1];
            }
        }
        return cnt[n];
    }
};