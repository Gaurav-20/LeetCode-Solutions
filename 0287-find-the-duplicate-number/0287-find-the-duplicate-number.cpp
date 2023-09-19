class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) {
            return -1;
        }
        int tortoise = 0, hare = 0;
        while (true) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if (tortoise == hare) {
                break;
            }
        }
        tortoise = 0;
        while (hare != tortoise) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};