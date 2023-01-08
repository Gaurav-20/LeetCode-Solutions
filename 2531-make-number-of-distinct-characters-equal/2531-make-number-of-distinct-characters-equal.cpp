class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> f1(26), f2(26);
        for (char c : word1) {
            f1[c - 'a']++;
        }
        for (char c : word2) {
            f2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (f1[i] > 0 && f2[j] > 0) {
                    f1[i]--, f2[i]++;
                    f1[j]++, f2[j]--;
                    int ct1 = 0, ct2 = 0;
                    for (int i = 0; i < 26; i++) {
                        ct1 += f1[i] > 0;
                        ct2 += f2[i] > 0;
                    }
                    if (ct1 == ct2) {
                        return true;
                    }
                    f1[i]++, f2[i]--;
                    f1[j]--, f2[j]++;
                }
            }
        }
        return false;
    }
};