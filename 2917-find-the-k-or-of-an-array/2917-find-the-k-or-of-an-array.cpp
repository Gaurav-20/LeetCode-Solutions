class Solution {
public:
    void updateNumberOfBits(vector<int>& bits, int num) {
        for (int i = 0; i < 32; i++) {
            bits[i] += ((num >> i)) & 1;
        }
    }
    
    int findKOr(vector<int>& nums, int k) {
        vector<int> bits(32, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            updateNumberOfBits(bits, nums[i]);
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] >= k) {
                bits[i] = 1;
            } else {
                bits[i] = 0;
            }
            if (bits[i] == 1) {
                res += 1 << i;
            }
        }
        return res;
    }
};