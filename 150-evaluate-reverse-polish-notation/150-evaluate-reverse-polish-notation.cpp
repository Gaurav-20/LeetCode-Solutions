class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)>> mp = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        stack<int> st;
        for (string &s : tokens) {
            if (!mp.count(s)) {
                st.push(stoi(s));
            } else {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(mp[s](op2, op1));
            }
        }
        return st.top();
    }
};