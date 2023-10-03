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
            int num = nums[i];
            int count = 1;
		    for (int j = 1; st.count(num - j); j++) {
                st.erase(num - j);
                count++;
            }
		    for (int j = 1; st.count(num + j); j++) { 
                st.erase(num + j);
                count++;
            }
		    res = max(res, count);
        }
        return res;
    }
};