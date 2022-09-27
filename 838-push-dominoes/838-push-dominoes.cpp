class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();
        vector<int> left(len, 0), right(len, 0);
        char prev = '.';
        int count = 1;
        for (int i = len - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                prev = 'L';
                count = 1;
                continue;
            } else if (dominoes[i] == 'R') {
                prev = 'R';
            }
            if (prev == 'L' && dominoes[i] == '.') {
                left[i] = count++;
            }
        }
        prev = '.';
        count = 1;
        for (int i = 0; i < len; i++) {
            if (dominoes[i] == 'R') {
                prev = 'R';
                count = 1;
                continue;
            } else if (dominoes[i] == 'L') {
                prev = 'L';
            }
            if (prev == 'R' && dominoes[i] == '.') {
                right[i] = count++;
            }
        }
        string res = "";
        for (int i = 0; i < len; i++) {
            if (!left[i] && !right[i]) {
                res += dominoes[i];
            } else if (!left[i]) {
                res += 'R';
            } else if (!right[i]) {
                res += 'L';
            } else if (left[i] == right[i]) {
                res += '.';
            } else if (left[i] > right[i]) {
                res += 'R';
            } else {
                res += 'L';
            }
        }
        return res;
    }
};