class Solution {
public:
    void generate(string s, int open, int close, int n, vector<string>& res) {
        if (open == n && close == n) {
            res.push_back(s);
            return;
        } else if (open > close) {
            if (open < n) {
                s += '(';
                generate(s, open + 1, close, n, res);
                s.pop_back();
            }
            if (close < n) {
                s += ')';
                generate(s, open, close + 1, n, res);
                s.pop_back();
            }
        } else if (open == close) {
            s += '(';
            generate(s, open + 1, close, n, res);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", 0, 0, n, res);
        return res;
    }
};