class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount = 0;
        bool containsZero = false;
        for (int& num : nums) {
            containsZero |= (num == 0);
            negCount += (num < 0);
        }
        return (containsZero) ? 0 : ((negCount % 2 == 0) ? 1 : -1);
    }
};