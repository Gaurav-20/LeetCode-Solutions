class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int res = total;
        for (int i = k - 1, j = cardPoints.size() - 1; i >= 0; i--, j--) {
            total += cardPoints[j] - cardPoints[i]; 
            res = max(res, total);
        }
        return res;
    }
};