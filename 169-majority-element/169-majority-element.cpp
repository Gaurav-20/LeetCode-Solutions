class Solution {
public:
    int majorityElement(vector<int>& arr) {
        // Moore's Voting Algorithm
        int votes = 0, candidate = -1;
        for (auto curr : arr) {
            if (candidate == -1) {
                candidate = curr;
            }
            if (curr == candidate) {
                votes++;
            } else {
                votes--;
            }
            if (votes == 0) {
                candidate = -1;
            }
        }
        return candidate;
    }
};