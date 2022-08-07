class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int x = nums[j] - nums[i];
                    int y = nums[k] - nums[j];
                    if (y == x && x == diff) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};