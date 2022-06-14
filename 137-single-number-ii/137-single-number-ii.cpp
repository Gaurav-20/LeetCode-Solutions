class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> freq(32, 0);
        for (int num : nums) {
            for (int i = 31; i >= 0; i--) {
                if (num & (1 << i)) {
                    freq[i]++;
                }
            }
        }
        for (int i = 0; i < 32; i++) {
            freq[i] %= 3;
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += freq[i] * (1 << i);
        }
        return res;
    }
};