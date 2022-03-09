const int MOD = 1e9 + 7;

long long mul(long long a, long long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long fastpow(long long a, long long b, int m = MOD) { 
    long long res = 1;
    a %= m;
    while (b > 0) { 
        if (b & 1) 
            res = (res * a) % m; 
        a = (a * a) % m; 
        b >>= 1; 
    } 
    return res;
}

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long res = 1;
        res = mul(res, fastpow(5, ceil(n / 2.0)));
        res = mul(res, fastpow(4, n / 2));
        return (int) res % MOD;
    }
};