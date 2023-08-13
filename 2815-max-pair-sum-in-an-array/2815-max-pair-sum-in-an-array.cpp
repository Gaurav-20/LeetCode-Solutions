class Solution {
public:
    int maxDigit(int n) {
        int res = 0;
        while (n > 0) {
            res = max(res, n % 10);
            n /= 10;
        }
        return res;
    }
    
    int maxSum(vector<int>& nums) {
        vector<vector<int>> count(10);
        for (int& num: nums) {
            count[maxDigit(num)].push_back(num);
        }
        for (vector<int>& v: count) {
            sort(v.begin(), v.end(), greater<int>());
        }
        int res = -1;
        for (int i = 9; i >= 0; i--) {
            if (count[i].size() >= 2) {
                res = max(res, count[i][0] + count[i][1]);
            }
        }
        return res;
    }
};