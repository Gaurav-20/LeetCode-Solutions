class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char c : s) {
            if (res.size() > 0 && res.back() == c) {
                res.pop_back();
            } else {
                res += c;
            }
        }
        return res;
    }
};