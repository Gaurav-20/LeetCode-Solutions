class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int& stone : stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if (first == second) {
                continue;
            } else {
                pq.push(first - second);
            }
        }
        if (pq.size() == 0) {
            return 0;
        }
        return pq.top();
    }
};