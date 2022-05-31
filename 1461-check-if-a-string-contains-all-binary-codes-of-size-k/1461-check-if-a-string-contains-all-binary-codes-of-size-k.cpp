class Solution {
public:
    long long toInt(string s, int k) {
        long long res = 0;
        for (int i = k - 1; i >= 0; i--) {
            res = (res * 2) + (s[i] - '0');
        }
        return res;
    }
    
    bool hasAllCodes(string s, int k) {
        int len = s.size();
        if (len < (1 << k)) {
            return false;
        }
        string temp = "";
        for (int i = 0; i < k; i++) {
            temp += s[i];
        }
        unordered_set<long long> st;
        st.insert(toInt(temp, k));
        for (int i = k; i < len; i++) {
            temp.erase(0, 1);
            temp += s[i];
            st.insert(toInt(temp, k));
        }
        return st.size() == (1LL << k);
    }
};