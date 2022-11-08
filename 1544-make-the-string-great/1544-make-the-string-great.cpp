class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && tolower(st.top()) == tolower(s[i]) && s[i] != st.top()) {
                st.pop();
                continue;
            } else {
                st.push(s[i]);
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};