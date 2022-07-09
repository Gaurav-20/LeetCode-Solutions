class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        long long res = 0;
        deque<int> dq;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);
            while (!dq.empty() && res > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() >= i + k) {
                dq.pop_front();
            }
            nums[i] = res;
        }
        return (int) res;
    }
};