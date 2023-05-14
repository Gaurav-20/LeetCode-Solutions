const int MOD = 1e9 + 7;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        long long res = 0, sum = 0;
        sort(nums.begin(), nums.end());
        for (int x: nums) {
            res = (res + (sum + x) * x % MOD * x % MOD) % MOD;
            sum = (sum * 2 + x) % MOD;
        }
        return res;
    }
};