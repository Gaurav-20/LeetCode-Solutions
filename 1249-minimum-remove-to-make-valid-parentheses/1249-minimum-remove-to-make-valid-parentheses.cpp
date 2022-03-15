class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string res = "";

        for (auto& c : s) {
            if (c == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    continue;
                }
            }
            if (c == '(') {
                st.push(c);
            }
            res += c;
        }
        while (!st.empty()) {
            res.erase(res.find_last_of(st.top()), 1);
            st.pop();
        }
        return res;
    }
};