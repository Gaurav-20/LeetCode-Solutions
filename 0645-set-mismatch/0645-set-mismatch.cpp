class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& n : nums) {
            mp[n]++;
        }
        vector<int> res(2);
        for (int i = 1; i <= nums.size(); i++) {
            if (mp[i] == 0) {
                res[1] = i;
            }
            if (mp[i] == 2) {
                res[0] = i;
            }
        }
        return res;
    }
};