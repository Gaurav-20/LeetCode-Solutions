class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for (int i : nums) {
            s.insert(i);
        }
        sort(nums.begin(), nums.end());
        int res = 0, mx = nums.back();
        for (int i = 0; i < n; i++) {
            long long curr = nums[i];
            int len = 0;
            while (s.find(curr) != s.end()) {
                len++;
                curr = curr * curr;
                if (curr > mx) {
                    break;
                }
            }
            res = max(res, len);
        }
        return res < 2 ? -1 : res;
    }
};