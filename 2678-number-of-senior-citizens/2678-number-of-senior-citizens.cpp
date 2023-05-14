class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (string str: details) {
            if (str[11] > '6' || (str[11] == '6' && str[12] >= '1')) {
                res++;
            }
        }
        return res;
    }
};