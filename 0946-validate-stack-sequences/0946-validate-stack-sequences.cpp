class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int popIdx = 0, n = pushed.size();
        vector<int> st;
        for (int& p : pushed) {
            st.push_back(p);
            while (st.size() > 0 && popIdx < n && popped[popIdx] == st.back()) {
                st.pop_back();
                popIdx++;
            }
        }
        return popIdx == n;
    }
};