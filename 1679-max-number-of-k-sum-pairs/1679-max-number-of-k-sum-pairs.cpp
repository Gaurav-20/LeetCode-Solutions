class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int operations = 0;
        unordered_map<int, int> hash;
        for (int& n : nums) {
            if (hash[k - n] > 0) {
                operations++;
                hash[k - n]--;
            } else {
                hash[n]++;
            }
        }
        return operations;
    }
};