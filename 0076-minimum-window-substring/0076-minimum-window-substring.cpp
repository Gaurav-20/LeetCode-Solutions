class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        for (char c: t) {
            mp[c]++;
        }
        int counter = t.size(), begin = 0, end = 0, resLen = INT_MAX, resStart = 0;
        while (end < s.size()) {
            if (mp[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (end - begin < resLen) {
                    resStart = begin;
                    resLen = end - begin;
                }
                if (mp[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }
        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }
};