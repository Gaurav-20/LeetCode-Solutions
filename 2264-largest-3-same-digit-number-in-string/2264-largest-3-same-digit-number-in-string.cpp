class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        if (n < 3) {
            return "";
        }
        string res = "";
        for (int i = 2; i < n; i++) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
                if (res.size() == 0 || res[0] < num[i]) {
                    res = "";
                    res += num[i];
                    res += num[i];
                    res += num[i];
                }
            }
        }
        return res;
    }
};