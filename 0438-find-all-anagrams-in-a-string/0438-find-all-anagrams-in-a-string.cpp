class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (m > n) {
            return {};
        }
        vector<int> vecp(26, 0);
        vector<int> window(26, 0);
        
        for (int i = 0; i < m; i++) {
            vecp[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        
        vector<int> res;
        if (vecp == window) {
            res.push_back(0);
        }
        for (int i = m; i < n; i++) {
            window[s[i - m] - 'a']--;
            window[s[i] - 'a']++;
            if (vecp == window) {
                res.push_back(i - m + 1);
            }
        }
        return res;
    }
};