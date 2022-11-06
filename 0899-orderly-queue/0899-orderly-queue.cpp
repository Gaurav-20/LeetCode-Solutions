class Solution {
public:
    
    string orderlyQueue(string s, int k) {
        string res = s;
        if (k == 1) {
            for (int i = 0; i < s.size(); i++) {
                s = s.substr(1) + s[0];
                res = min(res, s);
            }
        } else {
            sort(res.begin(), res.end());
        }
        return res;
    }
};