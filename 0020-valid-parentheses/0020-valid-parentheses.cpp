class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> comp;
        comp[')'] = '(';
        comp['}'] = '{';
        comp[']'] = '[';
        vector<char> st;
        for (char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            } else if (st.size() > 0 && comp[c] == st.back()) {
                st.pop_back();
            } else {
                return false;
            }
        }
        return st.size() == 0;
    }
};