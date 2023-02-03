class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int n = s.size();
        unordered_map<int, vector<char>> mp;
        int row = 0, step = 1;
        for (int i = 0; i < n; i++) {
            mp[row].push_back(s[i]);
            if (row == 0) {
                step = 1;
            } else if (row == numRows - 1) {
                step = -1;
            }
            row += step;
        }
        string res;
        for (int i = 0; i < numRows; i++) { 
            for (char c : mp[i]) {
                res += c;
            }
        }
        return res;
    }
};