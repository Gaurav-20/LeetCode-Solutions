class Solution {
public:
    int find(map<int, int>& freq, int x) {
        int count = 0;
        for (auto it : freq) {
            count += it.second;
            if (count >= x) {
                return it.first;
            }
        }
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int, int> freq;
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0) {
                freq[nums[i]]++;
            }
        }
        vector<int> res;
        res.push_back(find(freq, x));
        for (int i = k; i < n; i++) {
            if (freq.count(nums[i - k]) > 0) {
                freq[nums[i - k]]--;
            }
            if (nums[i] < 0) {
                freq[nums[i]]++;
            }
            res.push_back(find(freq, x));
        }
        return res;
    }
};