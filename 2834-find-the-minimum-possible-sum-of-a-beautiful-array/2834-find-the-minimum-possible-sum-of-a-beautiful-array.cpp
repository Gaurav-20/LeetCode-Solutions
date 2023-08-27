class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long res = 0, ct = 1;
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i++) {
            while (mp[target - ct]) {
                ct++;
            }
            mp[ct] = true;
            res += ct;
            ct++;
        }
        return res;
    }
};