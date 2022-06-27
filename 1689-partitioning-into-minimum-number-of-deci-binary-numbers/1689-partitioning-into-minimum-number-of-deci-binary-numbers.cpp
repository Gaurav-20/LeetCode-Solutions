class Solution {
public:
    int minPartitions(string n) {
        int maxi = INT_MIN;
        for (char c : n) {
            maxi = max(maxi, c - '0');
        }
        return maxi;
    }
};