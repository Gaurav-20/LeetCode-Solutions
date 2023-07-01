class Solution {
public:
    int res = INT_MAX;
    
    void solve(int i, vector<int>& cookies, int k, vector<int>& mask) {
        if (i == cookies.size()) {
            int ans = INT_MIN;
            for (int i = 0; i < k; i++) {
                ans = max(mask[i], ans);
            }
            res = min(ans, res);
            return;
        }
        for (int it = 0; it < k; it++) {
            mask[it] += cookies[i];
            solve(i + 1, cookies, k, mask);
            mask[it] -= cookies[i];
            if (mask[it] == 0) {
                break;
            }
        }
        return;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {   
        vector<int> mask(k, 0);
        solve(0, cookies, k, mask);
        return res;
    }
};