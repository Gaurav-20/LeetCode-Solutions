class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // Sort costs O(nlogn), we just need the median so we can do the following
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + (n / 2), nums.end());
        // Fixing ths median element
        int median = nums[n / 2];
        // This way we fix the median element using the nth_element function
        // which costs O(n) only
        int minMoves = 0;
        for (auto it : nums) {
            minMoves += abs(it - median);
        }
        return minMoves;
    }
};