class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> freq(10);
        int bull = 0, cow = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                if (freq[secret[i] - '0']++ < 0) {
                    cow++;
                }
                if (freq[guess[i] - '0']-- >0) {
                    cow++;
                }
            }
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};