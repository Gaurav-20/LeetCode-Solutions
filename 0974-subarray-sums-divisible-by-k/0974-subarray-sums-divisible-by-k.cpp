class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freqCount(k);
        freqCount[0] = 1;
        int prefix = 0, res = 0;
        for (int a : nums) {
            prefix = (prefix + a % k + k) % k;
            res += freqCount[prefix]++;
        }
        return res;
    }
};