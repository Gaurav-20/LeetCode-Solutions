class Solution {
public:
    string sortString(string s) {
        vector<char> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string res = "";
        bool increasing = true;
        while (true) {
            bool remaining = false;
            if (increasing) {
                for (int i = 0; i < 26; i++) {
                    if (freq[i] == 0) {
                        continue;
                    } else {
                        res += i + 'a';
                        freq[i]--;
                    }
                    if (freq[i] > 0) {
                        remaining = true;
                    }
                }
            } else {
                for (int i = 25; i >= 0; i--) {
                    if (freq[i] == 0) {
                        continue;
                    } else {
                        res += i + 'a';
                        freq[i]--;
                    }
                    if (freq[i] > 0) {
                        remaining = true;
                    }
                }
            }
            if (!remaining) {
                break;
            }
            increasing = !increasing;
        }
        return res;
    }
};