class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int bitsA = __builtin_popcount(a), bitsB = __builtin_popcount(b);
            return (bitsA < bitsB) || ((bitsA == bitsB) && a < b);
        });
        return arr;
    }
};