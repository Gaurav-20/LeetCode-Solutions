class Solution {
public:
    bool timeEfficientSolution(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (int& num: nums) {
            frequency[num]++;
        }
        for (auto freq: frequency) {
            if (freq.second & 1) {
                return false;
            }
        }
        return true;
    }
    
    bool spaceEfficientSolution(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2) {
            if (nums[i] != nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    bool divideArray(vector<int>& nums) {
        return timeEfficientSolution(nums);
        // return spaceEfficientSolution(nums);
    }
};