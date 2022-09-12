class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() - 1, score = 0, res = 0;
        while (low <= high) {
            if (power >= tokens[low]) {
                score++;
                power -= tokens[low++];
                res = max(res, score);
            } else if (score > 0) {
                score--;
                power += tokens[high--];
            } else {
                break;
            }
        }
        return res;
    }
};