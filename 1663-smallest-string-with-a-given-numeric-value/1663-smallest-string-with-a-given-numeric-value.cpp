class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        for (int i = n; i > 0; i--) {
            int c = max(0, min(25, k - i));
            k -= c + 1;
            res += c + 'a';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};