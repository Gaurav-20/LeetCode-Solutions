class Solution {
public:
    string s1, s2, s3;
    int n1, n2, n3;
    int dp[101][101];
    
    bool solve(int i, int j, int k) {
        if (i == n1) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j == n2) {
            return s1.substr(i) == s3.substr(k);
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool possible = false;
        possible |= (s1[i] == s3[k] && solve(i + 1, j, k + 1)) || 
                    (s2[j] == s3[k] && solve(i, j + 1, k + 1));
        return dp[i][j] = possible;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        this->s1 = s1, this->s2 = s2, this->s3 = s3;
        if (n1 + n2 != n3) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};