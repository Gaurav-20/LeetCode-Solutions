class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        st.push({ temperatures[n - 1], n - 1 });
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top().second - i;
            }
            st.push({ temperatures[i], i });
        }
        return res;
    }
};