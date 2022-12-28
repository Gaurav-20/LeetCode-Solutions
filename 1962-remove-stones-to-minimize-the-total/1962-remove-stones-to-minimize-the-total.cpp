class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0, n = piles.size();
        for (int i = 0; i < n; i++) {
            pq.push(piles[i]);
            sum += piles[i];
        }
        for (int i = 0; i < k; i++) {
            int currMaxPile = pq.top();
            pq.pop();
            sum -= currMaxPile / 2;
            currMaxPile -= currMaxPile / 2;
            if (currMaxPile > 0) {
                pq.push(currMaxPile);
            }
        }
        return sum;
    }
};