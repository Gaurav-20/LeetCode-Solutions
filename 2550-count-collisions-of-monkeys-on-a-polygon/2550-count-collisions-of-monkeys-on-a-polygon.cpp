#define ll long long
const ll MOD = 1e9 + 7;

class Solution {
public:
    ll fastpow(ll a, ll b, ll m = MOD) { ll res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
    
    int monkeyMove(int n) {
        ll res = fastpow(2, n);
        res = (res - 2 + MOD) % MOD;
        return res;
    }
};