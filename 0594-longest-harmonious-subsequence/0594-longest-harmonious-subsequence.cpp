class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        int res = 0;
        for (auto it : freq) {
            if (freq.count(it.first - 1)) {
                res = max(res, freq[it.first - 1] + it.second);
            }
            if (freq.count(it.first + 1)) {
                res = max(res, freq[it.first + 1] + it.second);
            }
        }
        return res;
    }
};