class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26, 0);
        for (char x : magazine) {
            hash[x - 'a']++;
        }
        for (char x : ransomNote) {
            if (hash[x - 'a'] == 0)
                return false;
            hash[x - 'a']--;
        }
        return true;
    }
};