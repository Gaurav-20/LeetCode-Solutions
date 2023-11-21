const int MOD = 1000000007;

class Solution {
public:
    int rev(int num) {
        int res = 0;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> sumExist;
        int nicePairsCount = 0;
        for (auto& num: nums) {
            int currSum = num - rev(num);
            nicePairsCount += sumExist[currSum];
            nicePairsCount %= MOD;
            sumExist[currSum]++;
        }
        return nicePairsCount;
    }
};