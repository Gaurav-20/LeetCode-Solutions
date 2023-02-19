class Solution {
public:
    
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s;
        for (int& n : nums) {
            s.insert(n);
        }
        int res = 1;
        for (int i = 0; i < 32; i++) {
            if (s.find(res) == s.end()) {
                return res;
            }
            res *= 2;
        }
        return -1;
    }
};