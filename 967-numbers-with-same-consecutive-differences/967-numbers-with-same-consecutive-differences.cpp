class Solution {
public:
    
    int countDigits(long long num) {
        return floor(log10(num) + 1);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        queue<long long> q;
        unordered_set<long long> st;
        for (long long i = 1; i <= 9; i++) {
            st.insert(i);
            q.push(i);
        }
        while (!q.empty()) {
            long long curr = q.front();
            q.pop();
            if (countDigits(curr) == n) {
                res.push_back(curr);
                continue;
            }
            int last = curr % 10;
            if (last + k <= 9) {
                curr = (curr * 10) + last + k;
                if (st.find(curr) == st.end()) {
                    q.push(curr);
                    st.insert(curr);
                }
                curr /= 10;
            }
            if (last - k >= 0) {
                curr = curr * 10 + last - k;
                if (st.find(curr) == st.end()) {
                    q.push(curr);
                    st.insert(curr);
                }
                curr /= 10;
            }
        }
        return res;
    }
};