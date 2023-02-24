class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxHeap;
        int mini = INT_MAX;
        for (int n : nums) {
            if (n & 1) {
                n *= 2;
            }
            mini = min(mini, n);
            maxHeap.push(n);
        }
        int res = INT_MAX;
        while (maxHeap.top() % 2 == 0) {
            int maxi = maxHeap.top();
            maxHeap.pop();
            res = min(res, maxi - mini);
            mini = min(mini, maxi / 2);
            maxHeap.push(maxi / 2);
        }
        res = min(res, maxHeap.top() - mini);
        return res;
    }
};