class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<int> vis(26, 0);
        
        for (char& c: s) {
            freq[c - 'a']++;
        }

        string res = "";
        for (char& c: s) {
            freq[c - 'a']--;
            if (vis[c - 'a'] == 0) {
                while (res.size() > 0 && res.back() > c && freq[res.back() - 'a'] > 0) {
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                res.push_back(c);
                vis[c - 'a'] = 1;
            }
        }
        return res;
    }
};