class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string s1 = str, s2 = str;
        int i;
        int n = str.size();
        for (i = 0; i < n; i++) {
            if (s1[i] != '9'){
                break;
            }
        }
        if (i == n) {
            return num;
        }
        char c = s1[i];
        char c1 = s1[0];
        for (i = 0; i < n; i++) {
            if (s1[i] == c) {
                s1[i] = '9';
            }
            if (s2[i] == c1) {
                s2[i] = '0';
            }
        }
        return (stoi(s1) - stoi(s2));
    }
};