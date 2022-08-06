class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minElement = *min_element(nums.begin(), nums.end());
        long long res = 0;
        for (auto num : nums) {
            res += num - minElement;
        }
        return (int) res;
    }
};