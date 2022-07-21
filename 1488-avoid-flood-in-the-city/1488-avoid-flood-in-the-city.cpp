class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> st;
        unordered_map<int, int> mp;
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                st.insert(i + 1);
            } else {
                if (mp[rains[i]] == 0) {
                    mp[rains[i]] = i + 1;
                } else {
                    int low = mp[rains[i]], high = i + 1;
                    auto it = st.lower_bound(low);
                    if (st.empty() || it == st.end() || (*it) > high) {
                        return {};
                    } else {
                        res[(*it) - 1] = rains[i];
                    }
                    mp[rains[i]] = high;
                    st.erase(it);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                res[i] = -1;
            }
        }
        return res;
    }
};