const int mod = 1e9 + 7;
bool computed = false;
long long dp[20005] = { -1 };

class Solution {
public:
    int countVowelPermutation(int n) {
        if (!computed) {
            computed = true;
            long long aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
            for (int i = 1; i <= 20004; i++) {
                dp[i] = (aCount + eCount + iCount + oCount + uCount) % mod;
                long long aCountNext = (eCount + iCount + uCount) % mod;
                long long eCountNext = (aCount + iCount) % mod;
                long long iCountNext = (eCount + oCount) % mod;
                long long oCountNext = (iCount) % mod;
                long long uCountNext = (iCount + oCount) % mod;
                aCount = aCountNext;
                eCount = eCountNext;
                iCount = iCountNext;
                oCount = oCountNext;
                uCount = uCountNext;
            }
        }
        return dp[n];
    }
};