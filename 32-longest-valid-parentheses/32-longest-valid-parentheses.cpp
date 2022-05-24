class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n <= 1) {
            return 0;
        }
        int curMax = 0;
        vector<int> longest(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    longest[i] = (i - 2) >= 0 ? (longest[i - 2] + 2) : 2;
                    curMax = max(longest[i], curMax);
                } else {
                    int prevIndex = i - longest[i - 1] - 1;
                    if (prevIndex >= 0 && s[prevIndex] == '(') {
                        longest[i] = longest[i - 1] + 2 + 
                            ((prevIndex - 1 >= 0) ? longest[prevIndex - 1] : 0);
                        curMax = max(longest[i], curMax);
                    }
                }
            }
        }
        return curMax;
    }
};