class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.size();
        if (len < k) {
            return false;
        }
        unordered_set<string> st;
        for (int i = 0; i <= len - k; i++) {
            st.insert(s.substr(i, k));
        }
        return st.size() == (1 << k);
    }
};