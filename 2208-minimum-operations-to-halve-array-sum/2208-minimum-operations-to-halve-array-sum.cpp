class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        double sum = 0.0;
        priority_queue<double> pq;
        for (int i = 0; i < n; i++) {
            double curr = (double) nums[i];
            sum += curr;
            pq.push(curr);
        }
        double minReduction = sum / 2.0, reduced = 0.0;
        int operations = 0;
        while (true) {
            operations++;
            double curr = pq.top();
            pq.pop();
            reduced += curr / 2.0;
            curr /= 2.0;
            pq.push(curr);
            if (reduced >= minReduction) {
                break;
            }
        }
        return operations;
    }
};