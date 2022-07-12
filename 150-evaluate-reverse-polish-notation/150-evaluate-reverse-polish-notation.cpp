class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& s : tokens) {
            if (s.size() > 1 || isdigit(s[0])) {
                st.push(stoi(s));
            } else {
                int x2 = st.top(); st.pop();
                int x1 = st.top(); st.pop();
                int res = 0;
                switch (s[0]) {
                    case '+': res = x1 + x2; break;
                    case '-': res = x1 - x2; break;
                    case '*': res = x1 * x2; break;
                    case '/': res = x1 / x2; break;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};