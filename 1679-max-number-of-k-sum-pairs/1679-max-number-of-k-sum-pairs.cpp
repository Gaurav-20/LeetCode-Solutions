class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int operations = 0;
        map<int, int> hash;
        for (int& n : nums) {
            hash[n]++;
        }
        for (auto it : hash) {
            int curr = it.first;
            int comp = k - curr;
            if (curr == comp) {
                if (hash[curr] > 1) {
                    operations += hash[curr] / 2;
                    hash[curr] = 0;
                }
            } else {
                if (hash[curr] > 0 && hash[comp] > 0) {
                    operations += min(hash[curr], hash[comp]);
                    hash[curr] = hash[comp] = 0;
                }
            }
        }
        return operations;
    }
};