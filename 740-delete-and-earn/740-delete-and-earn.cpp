class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for (int& n : nums) {
            mp[n]++;
            mx = max(mx, n);
        }
        vector<int> excl(mx + 1, 0), incl(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            excl[i] = max(excl[i - 1], incl[i - 1]);
            incl[i] = excl[i - 1] + (i * mp[i]);
        }
        return max(excl[mx], incl[mx]);
    }
};