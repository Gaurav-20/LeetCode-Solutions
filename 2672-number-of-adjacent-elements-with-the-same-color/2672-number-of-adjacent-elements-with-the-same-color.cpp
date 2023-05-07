class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n), res;
        int components = 0;
        for (auto& q: queries) {
            int index = q[0], color = q[1];
            if (nums[index] != 0) {
                if (index > 0 && nums[index] == nums[index - 1]) {
                    components--;
                }
                if (index + 1 < n && nums[index] == nums[index + 1]) {
                    components--;
                }
            }
            nums[index] = color;
            if (index > 0 && nums[index] == nums[index - 1]) {
                components++;
            }
            if (index + 1 < n && nums[index] == nums[index + 1]) {
                components++;
            }
            res.push_back(components);
        }
        return res;
    }
};