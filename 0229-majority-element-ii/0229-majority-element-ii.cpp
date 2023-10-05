class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // There can be atmost two majority elements
        int n = nums.size();
        int candidate1 = INT_MIN, candidate2 = INT_MIN; // Any number outside of constraint numbers
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int i = 0; i < n; i++) {
            count1 += (nums[i] == candidate1);
            count2 += (nums[i] == candidate2);
        }
        vector<int> res;
        if (count1 > n / 3) {
            res.push_back(candidate1);
        }
        if (count2 > n / 3) {
            res.push_back(candidate2);
        }
        return res;
    }
};