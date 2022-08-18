class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        vector<int> freq;
        for (auto it : mp) {
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int count = n, res = 0, i = 0;
        while (count > n / 2) {
            count -= freq[i++];
            res++;
        }
        return res;
    }
};