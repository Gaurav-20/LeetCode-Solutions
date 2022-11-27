int signum(int x) {
    return (x > 0) ? 1 : (x < 0) ? -1 : 0;
}

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), index = -1;
        for (int i = 0; i < n; i++) {
            nums[i] = signum(nums[i] - k);
            if (nums[i] == 0) {
                index = i;
            }
        }
        int res = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        for (int i = index; i >= 0; i--) {
            sum += nums[i];
            mp[sum]++;
        }
        sum = 0;
        for (int i = index; i < n; i++) {
            sum += nums[i];
            int f = -1 * sum;
            res += mp[f];
            res += mp[f + 1];
        }
        return res; 
        
    }
};