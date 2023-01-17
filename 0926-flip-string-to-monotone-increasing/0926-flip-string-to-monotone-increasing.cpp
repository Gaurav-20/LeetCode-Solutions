class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flip = 0;
        int oneCount = 0 ;
        for (char c : s) {
            if (c == '0') {
                if (oneCount != 0) {
                    flip++;
                }
            } else {
                oneCount++;
            }
            flip = min(flip, oneCount) ;
        }
        return flip;
    }
};