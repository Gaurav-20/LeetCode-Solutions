class Solution {
public:
    
    bool isValid(string s) {
        map<char, char> comp;
        comp[')'] = '(';
        comp['}'] = '{';
        comp[']'] = '[';
        stack<char> st;
        bool flag = true;
        for (char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (!st.empty() && comp[c] == st.top()) {
                st.pop();
            } else {
                flag = false;
                break;
            }
        }
        return flag && st.empty();
    }
};