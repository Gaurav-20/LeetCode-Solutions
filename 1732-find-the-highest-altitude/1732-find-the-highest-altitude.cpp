class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, curr = 0;
        for (int g: gain) {
            curr += g;
            res = max(curr, res);
        }
        return res;
    }
};