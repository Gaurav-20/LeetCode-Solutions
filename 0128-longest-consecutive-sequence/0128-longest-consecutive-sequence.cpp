class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i] - 1) == st.end()) {
                int curr = nums[i], count = 0;
                while (st.find(curr) != st.end()) {
                    count++;
                    curr++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};