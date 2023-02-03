class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.size();
        vector<vector<char>> vec(numRows, vector<char>(n, ' '));
        int row = 0, col = 0;
        for (int i = 0; i < n; i++) {
            if (row == numRows) {
                row--;
                row--;
                col++;
                while (row > 0) {
                    vec[row][col] = s[i++];
                    if (i == n) {
                        break;
                    }
                    row--;
                    col++;
                }
                i--;
            } else {
                vec[row][col] = s[i];
                row++;
            }
        }
        string res;
        for (vector<char> x : vec) { 
            for (char c : x) {
                if (c == ' ') {
                    continue;
                } else {
                    res += c;
                }
            }
        }
        return res;
    }
};