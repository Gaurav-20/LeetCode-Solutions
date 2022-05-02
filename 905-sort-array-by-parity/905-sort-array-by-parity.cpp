bool comp(const int& a, const int& b) {
    return a % 2 < b % 2;
}

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};