class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string res; // using string res as a stack
        for (int i = 0; i < n; i++) {
            if (res.size() > 0 && tolower(res.back()) == tolower(s[i]) && s[i] != res.back()) {
                res.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};