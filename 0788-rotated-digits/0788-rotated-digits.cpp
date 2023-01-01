class Solution {
public:
    bool isGoodInteger(int n) {
        string curr = to_string(n);
        string next = curr;
        for (char& c : next) {
            if (c == '0' || c == '1' || c == '8') {
                continue;
            } else if (c == '2' || c == '5') {
                if (c == '2') {
                    c = '5';
                } else {
                    c = '2';
                }
            } else if (c == '6' || c == '9') {
                if (c == '6') {
                    c = '9';
                } else {
                    c = '6';
                }
            } else {
                return false;
            }
        }
        return next != curr;
    }
    
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (isGoodInteger(i)) {
                res++;
            }
        }
        return res;
    }
};