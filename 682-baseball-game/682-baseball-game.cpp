class Solution {
public:
    bool isNumber(string s) {
        int i = s[0] == '-' ? 1 : 0;
        int len = size(s);
        while (i < len && isdigit(s[i])) {
            i++;
        }
        return i == len;
    }
    
    int calPoints(vector<string>& ops) {
        int score = 0;
        vector<int> v;
        for (string& s : ops) {
            if (isNumber(s)) {
                v.push_back(stoi(s));
            } else if (s == "+") {
                int sz = size(v);
                v.push_back(v[sz - 1] + v[sz - 2]);
            } else if (s == "D") {
                v.push_back(v.back() * 2);
            } else {
                v.pop_back();
            }
        }
        int res = accumulate(v.begin(), v.end(), 0);
        return res;
    }
};