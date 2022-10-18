class Solution {
public:
    vector<pair<int, int>> helper1(string& s) {
        int n = s.size();
        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++) {
            char curr = s[i];
            int ct = 0;
            while (i < n && s[i] == curr) {
                ct++;
                i++;
            }
            res.push_back({ curr - '0', ct });
            if (i < n) {
                i--;
            }
        }
        return res;
    }
    
    string helper2(vector<pair<int, int>>& v) {
        int n = v.size();
        string res;
        for (int i = 0; i < n; i++) {
            res += v[i].second + '0';
            res += v[i].first + '0';
        }
        return res;
    }
    
    string countAndSay(int n) {
        string res = "1";
        if (n == 1) {
            return res;
        }
        for (int i = 2; i <= n; i++) {
            vector<pair<int, int>> temp = helper1(res);
            res = helper2(temp);
        }
        return res;
    }
};