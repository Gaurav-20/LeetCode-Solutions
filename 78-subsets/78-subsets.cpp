class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> temp;
            int it = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp.push_back(nums[it]);
                }
                it++;
            }
            result.push_back(temp);
        }
        return result;
    }
};