class Solution {
public:
    bool isNumeric(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                // okay
            } else {
                return false;
            }
        }
        return true;
    }
    
    int maximumValue(vector<string>& strs) {
        int res = INT_MIN;
        for (string s : strs) {
            if (isNumeric(s)) {
                res = max(res, stoi(s));
            } else {
                res = max(res, (int) s.size());
            }
        }
        return res;
    }
};