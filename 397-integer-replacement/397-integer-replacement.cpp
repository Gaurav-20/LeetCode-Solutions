class Solution {
public:
    unordered_map<long long, long long> mp;
    long long solve(long long n) {
        if (n <= 1) {
            return 0;
        }
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        if (n & 1) {
            return mp[n] = 1 + min(solve(n + 1), solve(n - 1));
        }
        return mp[n] = 1 + solve(n / 2);
    }
    
    int integerReplacement(int n) {
        return (int) solve(n);
    }
};