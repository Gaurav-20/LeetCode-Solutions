class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> groupedAnagrams;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagrams[key].push_back(str);
        }
        for (auto it : anagrams) {
            groupedAnagrams.push_back(it.second);
        }
        return groupedAnagrams;
    }
};