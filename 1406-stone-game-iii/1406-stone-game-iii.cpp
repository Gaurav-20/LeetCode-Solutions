class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int a = 0, b = 0, c = 0;
        for (int i = n - 1; i >= 0; i--) {
            int score = INT_MIN;
            score = max(score, stoneValue[i] - a);
            if (i + 1 < stoneValue.size()) {
                score = max(score, stoneValue[i] + stoneValue[i + 1] - b);
            }
            if (i + 2 < stoneValue.size()) {
                score = max(score, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - c);
            }
            c = b;
            b = a;
            a = score;
        }
        return (a > 0) ? "Alice" : a == 0 ? "Tie" : "Bob";
    }
};