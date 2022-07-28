class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> hash(26, 0);
        for (char& x : t) {
            hash[x - 'a']++;
        }
        for (char& x : s) {
            if (hash[x - 'a'] == 0) {
                return false;
            }
            hash[x - 'a']--;
        }
        return true;
    }
};