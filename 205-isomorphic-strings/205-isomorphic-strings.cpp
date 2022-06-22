class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMap;
        unordered_map<char, bool> present;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (charMap.find(s[i]) != charMap.end()) {
                if (charMap[s[i]] != t[i])
                    return false;
            } else {
                if (present[t[i]]) {
                    return false;
                }
                charMap[s[i]] = t[i];
                present[t[i]] = true;
                
            }
        }
        return true;
    }
};