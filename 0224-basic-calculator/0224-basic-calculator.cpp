class Solution {
public:
    int calculate(string s) {
        int sum = 0, sign = 1, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                int val = 0;
                while (i < n && (s[i] >= '0' && s[i] <= '9')) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                sum += (val * sign);
                sign = 1;
                i--;
            } else if (ch == ')') {
                int poppedSign = st.top();
                st.pop();
                int preSum = st.top();
                st.pop();
                sum  = (sum * poppedSign) + preSum;
            } else if (ch == '(') {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            } else if (ch == '-') {
                sign *= -1;
            }         
        }
        return sum;
    }
};