class Solution {
public:
    int longestConsecutive(vector<int>& numbers) {
        unordered_set<int> nums;
        for (int& n : numbers) {
            nums.insert(n);
        }
        int best = 0;
        for (auto x : nums) {
            if (nums.find(x - 1) == nums.end()) {
                int y = x + 1;
                while (nums.find(y) != nums.end()) {
                    y++;
                }
                best = max(best, y - x);
            }
        }
        return best;
    }
};