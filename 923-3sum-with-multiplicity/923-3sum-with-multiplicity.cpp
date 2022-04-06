class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> mp;
        for (int& a : arr) {
            mp[a]++;
        }
        long res = 0;
        for (auto it : mp) {
            for (auto it2 : mp) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!mp.count(k)) {
                    continue;
                }
                if (i == j && j == k) {
                    res += mp[i] * (mp[i] - 1) * (mp[i] - 2) / 6;
                } else if (i == j && j != k) {
                    res += mp[i] * (mp[i] - 1) / 2 * mp[k];
                } else if (i < j && j < k) {
                    res += mp[i] * mp[j] * mp[k];
                }
            }
        }
        return res % int(1e9 + 7);
    }
};