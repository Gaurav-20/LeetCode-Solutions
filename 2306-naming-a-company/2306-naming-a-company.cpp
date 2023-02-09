class Solution {
public:
    long long distinctNames(vector<string>& ideas) {        
        int n = ideas.size();
        unordered_set<string> st;
        for (auto s : ideas) {
            st.insert(s);
        }
        
        vector<vector<int>> tot(26, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            string s = ideas[i];            
            char old = s[0];
            for (int c = 0; c < 26; c++) {
                s[0] = char(c + 'a');
                if (!st.count(s)) {
                    tot[old - 'a'][c]++;
                }
            }
            s[0] = old;
        }
        
        long long res = 0;
        for (int a = 0; a < 26; a++) {
            for (int b = 0; b < 26; b++) {
                res += tot[a][b] * tot[b][a];
            }
        }
        return res;
    }
};