class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = { bitset<26>() };
        int res = 0; // will store number of unique chars in resultant string
        for (auto& s : arr) {
            bitset<26> a; // used to track unique chars
            for (char c : s) {
                a.set(c - 'a');
            }
            int n = a.count();
            if (n < s.size()) {
                continue; // duplicate chars in current string
            }

            for (int i = dp.size() - 1; i >= 0; i--) {
                bitset<26> c = dp[i];
                if ((c & a).any()) {
                    continue; // if 1 or more char common
                }
                dp.push_back(c | a); // valid concatenation
                res = max(res, (int)c.count() + n);
            }
        }
        return res;
    }
};