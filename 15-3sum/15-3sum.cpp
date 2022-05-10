class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return {};
        }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int target;
        for (int i = 0; i < len; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                target = -nums[i];
                int j = i + 1;
                int k = len - 1;
                int a, b;
                while (j < k) {
                    a = nums[j];
                    b = nums[k];
                    if (a + b == target) {
                        res.push_back({nums[i], a, b});
                        while (j < k && nums[j] == a) {
                            j++;
                        }                        
                        while (j < k && nums[k] == b) {
                            k--;
                        }
                    } else {
                        (a + b > target) ? k-- : j++;
                    }
                }
            }
        }
        return res;
    }
};