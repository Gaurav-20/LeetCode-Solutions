class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int curr = 0, prev = 0, prevToPrev = 0; // since we need only 3 values to be known
        for (int i = 2; i <= n; i++) {
            curr = min(prev + cost[i - 1], prevToPrev + cost[i - 2]);
            prevToPrev = prev;
            prev = curr;
        }
        return curr;
    }
};