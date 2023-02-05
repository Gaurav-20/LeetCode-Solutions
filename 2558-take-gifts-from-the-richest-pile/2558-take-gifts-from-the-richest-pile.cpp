class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (int gift : gifts) {
            pq.push(gift);
        }
        long long res = 0;
        for (int i = 0; i < k; i++) {
            int curr = pq.top();
            pq.pop();
            int root = sqrt(curr);
            pq.push(root);
        }
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};