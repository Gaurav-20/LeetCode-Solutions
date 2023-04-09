class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        // we could use a seive for optimal solution but not necessary here
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i])) {
                res = max(res, nums[i][i]);
            }
            if (isPrime(nums[i][n - 1 - i])) {
                res = max(res, nums[i][n - 1 - i]);
            }
        }
        return res;
    }
};