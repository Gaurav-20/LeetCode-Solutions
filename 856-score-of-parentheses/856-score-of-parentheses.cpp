class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for (char& c : s) {
            if (c == '(') {
                st.push(INT_MIN);
            } else {
                int ans = 0;
                if (!st.empty() && st.top() == INT_MIN) {
                    st.pop();
                    st.push(1);
                } else {
                    while (!st.empty() && st.top() != INT_MIN) {
                        ans += st.top();
                        st.pop();                        
                    }
                    st.pop();
                    st.push(ans * 2);
                }
            }
        }
        int score = 0;
        while (!st.empty()) {
            score += st.top();
            st.pop();
        }
        return score;
    }
};