class Solution {
public:
    bool isSimilar(string a, string b) {
        vector<int> f1(26, 0), f2(26, 0);
        for (char c : a) {
            f1[c - 'a']++;
        }
        for (char c : b) {
            f2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (f1[i] == 0 || f2[i] == 0) {
                if (f1[i] == 0 && f2[i] == 0) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    
    int similarPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(words[i], words[j])) {
                    res++;
                }
            }
        }
        return res;
    }
};