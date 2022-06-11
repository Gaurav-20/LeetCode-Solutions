class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        int len = nums.size();
        // We modify the given array to negative values, since the values are from 1 to n
        // there would be no negatives initially
        // The further algo is easily understandable
        // Since all numbers are positive, we can run a loop later to change all negative 
        // to positive, so in a way we don't modify the array
        for (int& x : nums) {
            int index = abs(x) - 1;
            if (nums[index] < 0) {
                duplicates.push_back(abs(index + 1));
            }
            nums[index] = -nums[index];
        }
        // revert back the array values as a good practice
        for (int& x : nums) {
            x = abs(x);
        }
        return duplicates;
    }
};