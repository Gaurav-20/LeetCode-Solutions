class Solution {
public:
    int solve(string answerKey, int k, char c) {
        int i = 0, j = 0, cnt = 0;
        int n = answerKey.size();
        int res = 0;
        while (j < n) {
            if (answerKey[j] == c) {
                cnt++;
            }
            while (i < n && cnt > k) {
                if (answerKey[i] == c) {
                    cnt--;
                }
                i++;
            }
            res = max(j - i + 1, res);
            j++;
        }
        return res;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
    }
};