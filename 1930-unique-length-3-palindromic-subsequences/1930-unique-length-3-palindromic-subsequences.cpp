class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> left(26, -1);
        vector<int> right(26, -1);
        int cur;
        for (int i = 0; i < s.size(); i++) {
            cur = s[i] - 'a';
            if (left[cur] == -1) {
                left[cur] = i;
            }
            right[cur] = i;
        }
        int res = 0;
        vector<bool> count(26, false);
        for (int i = 0; i < 26; i++) {
            if (left[cur] == -1) {
                continue;
            }
            fill(count.begin(), count.end(), false);
            for (int j = left[i] + 1; j < right[i]; j++) {
                if (!count[s[j] - 'a']) {
                    count[s[j]-'a']=true;
                    res++;
                }
            }
        }
        return res;
    }
};