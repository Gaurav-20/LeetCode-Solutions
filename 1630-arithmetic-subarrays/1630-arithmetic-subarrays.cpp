class Solution {
public:
    vector<int> getVectorSubarray(vector<int>& nums, int left, int right) {
        vector<int> out(right - left + 1);
        for (int i = left; i <= right; i++) {
            out[i - left] = nums[i];
        }
        return out;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int len = l.size();
        vector<bool> result(len);
        for (int i = 0; i < len; i++) {
            if (r[i] - l[i] <= 1) {
                result[i] = (r[i] - l[i]) == 1;
                continue;
            }
            vector<int> subarray = getVectorSubarray(nums, l[i], r[i]);
            sort(subarray.begin(), subarray.end());
            int diff = subarray[1] - subarray[0];
            bool isValidSequence = true;
            for (int i = 2; i < subarray.size(); i++) {
                if (subarray[i] - subarray[i - 1] != diff) {
                    isValidSequence = false;
                }
            }
            result[i] = isValidSequence;
        }
        return result;
    }
};