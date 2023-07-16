class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominant;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] * 2 > n) {
                dominant = nums[i];
            }
        }
        int dominantLeftFreq = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                dominantLeftFreq++;
            }
            int dominantRightFreq = freq[dominant] - dominantLeftFreq;
            if ((dominantLeftFreq * 2 > (i + 1)) && (dominantRightFreq * 2 > (n - i - 1))) {
                return i;
            }
        }
        return -1;
    }
};