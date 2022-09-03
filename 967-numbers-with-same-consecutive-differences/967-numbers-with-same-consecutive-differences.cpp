class Solution {
public:
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        queue<string> q;
        unordered_set<string> st;
        for (int c = 1; c <= 9; c++) {
            string temp = to_string(c);
            st.insert(temp);
            q.push(temp);
        }
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() == n) {
                res.push_back(stoi(curr));
                continue;
            }
            int last = curr.back() - '0';
            if (last + k <= 9) {
                curr.push_back(last + k + '0');
                if (st.find(curr) == st.end()) {
                    q.push(curr);
                    st.insert(curr);
                }
                curr.pop_back();
            }
            if (last - k >= 0) {
                curr.push_back(last - k + '0');
                if (st.find(curr) == st.end()) {
                    q.push(curr);
                    st.insert(curr);
                }
                curr.pop_back();
            }
        }
        return res;
    }
};