class Solution {
public:
    int getDiff(vector<int>& nums) {
        return abs(nums[0] - nums[1]);
    }
    
    vector<int> findClosest(int num) {
        int minDiff = INT_MAX;
        vector<int> res, temp;
        for (int i = 1; i <= sqrt(num) + 1; i++) {
            if (num % i == 0) {
                temp = { i, num / i };
                int diff = getDiff(temp);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = { i, num / i };
                }
            }
        }
        return res;
    }
    
    vector<int> closestDivisors(int num) {
        vector<int> numPlusOne = findClosest(num + 1);
        vector<int> numPlusTwo = findClosest(num + 2);
        return getDiff(numPlusOne) < getDiff(numPlusTwo) ? numPlusOne : numPlusTwo;
    }
};