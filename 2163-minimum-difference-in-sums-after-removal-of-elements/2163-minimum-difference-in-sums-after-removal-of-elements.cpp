class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int len = nums.size();
        int n = len / 3;
        
        priority_queue<int> pqLeft;
        priority_queue<int, vector<int>, greater<int>> pqRight;
        vector<long long> temp(len);
        
        long long res = LLONG_MAX, leftSum = 0, rightSum = 0;
        
        for (int i = len - 1; i >= n; i--) {
            pqRight.push(nums[i]);
            rightSum += nums[i];
            if (pqRight.size() > n) {
                rightSum -= pqRight.top();
                pqRight.pop();
            }
            if (pqRight.size() == n) {
                temp[i] = rightSum;
            }
        }
        
        for (int i = 0; i < len - n; i++) {
            pqLeft.push(nums[i]);
            leftSum += nums[i];
            if (pqLeft.size() > n) {
                leftSum -= pqLeft.top();
                pqLeft.pop();
            }
            if (pqLeft.size() == n) {
                res = min(res, leftSum - temp[i + 1]);
            }
        }
        
        return res;
    }
};