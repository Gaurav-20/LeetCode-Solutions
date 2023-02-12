class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        long long res = 0;
        while (i <= j) {
            if (i == j) {
                res += nums[i];
            } else {
                res += stoi(to_string(nums[i]) + to_string(nums[j]));
            }
            i++;
            j--;
        }
        return res;
    }
};