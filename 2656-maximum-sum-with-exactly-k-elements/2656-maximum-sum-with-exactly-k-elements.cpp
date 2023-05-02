class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int& num: nums) {
            pq.push(num);
        }
        int score = 0;
        for (int i = 0; i < k; i++) {
            int cur = pq.top();
            pq.pop();
            score += cur;
            pq.push(cur + 1);
        }
        return score;
    }
};