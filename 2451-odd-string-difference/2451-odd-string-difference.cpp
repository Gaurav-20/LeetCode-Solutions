class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        map<vector<int>, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            vector<int> v;
            for (int j = 1; j < word.size(); j++) {
                v.push_back(word[j] - word[j - 1]);
            }
            mp[v].push_back(i);
        }
        string res;
        for (auto it : mp) {
            if (it.second.size() == 1) {
                res = words[it.second[0]];
                break;
            }
        }
        return res;
    }
};