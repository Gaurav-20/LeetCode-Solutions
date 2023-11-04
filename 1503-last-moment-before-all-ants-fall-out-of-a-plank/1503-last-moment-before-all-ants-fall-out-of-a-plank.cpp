class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = left.size() ? *max_element(left.begin(), left.end()) : 0;
        int rightMin = right.size() ? *min_element(right.begin(), right.end()) : n;
        return max(leftMax, n - rightMin);
    }
};