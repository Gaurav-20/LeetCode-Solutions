class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = accumulate(target.begin(), target.end(), 0LL);
        priority_queue<int> pq(target.begin(), target.end());
        while (sum > 1 && pq.top() > sum / 2) {
            long long curr = pq.top();
            pq.pop();
            sum -= curr;
            if (sum <= 1) {
                return sum;
            }
            pq.push(curr % sum);
            sum += curr % sum;
        }
        return sum == target.size(); // all 1s
    }
};