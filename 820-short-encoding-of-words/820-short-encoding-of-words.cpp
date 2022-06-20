class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {    
        int res = 0;
        for (auto& word : words) {
            reverse(word.begin(), word.end());
        }
        set<string> s(words.begin(), words.end());
        for (auto it = s.begin(); next(it) != s.end(); ++it) {
            res += *it == next(it)->substr(0, it->size()) ? 0 : it->size() + 1;
        }
        return res + s.rbegin()->size() + 1;
    }
};