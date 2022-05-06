class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char& c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({c, 1});
            }
        }
        string res = "";
        while (!st.empty()) {
            char curr = st.top().first;
            int count = st.top().second;
            while (count--) {
                res += curr;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};