bool compare(const string& a, const string& b) {
    return (a.size() > b.size()) || (a.size() == b.size() && a > b);
}

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        return nums[k - 1];
    }
};