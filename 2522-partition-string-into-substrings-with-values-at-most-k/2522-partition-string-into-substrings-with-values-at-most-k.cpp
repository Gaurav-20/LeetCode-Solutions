class Solution {
public:
    int minimumPartition(string s, int k) {
        long long cur = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            long long temp = s[i] - '0';
            if (temp > k) {
                res = -1;
                break;
            }
            long long newcur = cur * 10 + temp;
            if (newcur < k) {
                cur = newcur;
            } else if (newcur == k) {
                res++;
                cur = 0;
            } else {
                cur = temp;
                res++;
            }
        }
        if (res != -1 && cur > 0) {
            res++;
        }
        return res;
    }
};