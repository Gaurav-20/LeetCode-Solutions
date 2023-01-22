class Solution {
    vector<vector<string>> res;
    vector<string> part;
public:
    
    bool isPalindrome(string& s, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high]) {
                return false;
            }
            low++, high--;
        }
        return true;
    }
    
    void solve(string s, int i, int n) {
        if (i == n) {
            res.push_back(part);
            return;
        }
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                solve(s, j + 1, n);
                part.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        solve(s, 0, n);
        return res;
    }
};