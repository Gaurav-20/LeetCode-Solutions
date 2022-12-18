class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        vector<pair<int, int>> st; // vector as a stack
        st.push_back({ temperatures[n - 1], n - 1 });
        for (int i = n - 2; i >= 0; i--) {
            while (st.size() > 0 && st.back().first <= temperatures[i]) {
                st.pop_back();
            }
            if (st.size() == 0) {
                res[i] = 0;
            } else {
                res[i] = st.back().second - i;
            }
            st.push_back({ temperatures[i], i });
        }
        return res;
    }
};