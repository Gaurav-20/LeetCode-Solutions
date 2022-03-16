class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int popIter = 0;
        for (int& x : pushed) {
            st.push(x);
            while (popIter < size(popped) && !st.empty() && st.top() == popped[popIter]) {
                st.pop();
                popIter++;
            }
        }
        return st.empty();
    }
};