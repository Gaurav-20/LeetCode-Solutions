class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> mp;
        int res = 0;
        for (string word: words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (mp[rev] > 0) {
                res++;
                mp[rev]--;
            }
            mp[word]++;
        }
        return res;
    }
};