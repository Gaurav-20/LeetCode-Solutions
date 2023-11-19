class Solution {
public:
    long long minimumSteps(string s) {
        reverse(s.begin(), s.end());
        long long steps = 0, zerosToLeft = 0;
        for (char& c: s) {
            if (c == '0') {
                zerosToLeft++;
            } else {
                steps += zerosToLeft;
            }
        }
        return steps;
    }
};