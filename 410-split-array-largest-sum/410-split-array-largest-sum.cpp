class Solution {
public:
    bool possible(vector<int>& nums, int mid, int m) {
        int numPartitions = 1, pages = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) {
                return false;
            }
            pages += nums[i];
            if (pages > mid) {
                numPartitions++;
                pages = nums[i];
            }
        }
        return numPartitions <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = *min_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (possible(nums, mid, m)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};