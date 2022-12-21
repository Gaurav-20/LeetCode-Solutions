class Solution {
public:
    void generate(string s, int open, int close, int n, vector<string>& res) {
        if (open == n && close == n) {
            res.push_back(s);
            return;
        }
        if (open < n) {
            generate(s + '(', open + 1, close, n, res);
        }
        if (open > close) {
            generate(s + ')', open, close + 1, n, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", 0, 0, n, res);
        return res;
    }
};