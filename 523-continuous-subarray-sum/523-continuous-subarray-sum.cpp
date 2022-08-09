class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, prev = 0;
        // prev stores the previous element, since we need atleast two elements
        // we store it one iteration later
        unordered_set<int> modk;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = sum % k;
            if (modk.find(mod) != modk.end()) {
                return true;
            }
            modk.insert(prev);
            prev = mod;
        }
        return false;
    }
};