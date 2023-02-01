class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() > str2.size()) {
            swap(str1, str2);
        }
        int m = str1.size(), n = str2.size();
        string res = "";
        for (int i = 1; i <= m; i++) {
            string prefix = str1.substr(0, i);
            int len = prefix.size();
            if (m % len == 0 && n % len == 0) {
                string temp1 = prefix;
                while (temp1.size() < m) {
                    temp1 += prefix;
                }
                string temp2 = prefix;
                while (temp2.size() < n) {
                    temp2 += prefix;
                }
                if (temp1 == str1 && temp2 == str2) {
                    res = (prefix.size() > res.size()) ? prefix : res;
                }
            }
        }
        return res;
    }
};