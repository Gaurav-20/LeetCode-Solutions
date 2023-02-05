class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string s;
        for (int n : nums) {
            s += to_string(n);
        }
        vector<int> res;
        for (char c : s) {
            res.push_back(c - '0');
        }
        return res;
    }
};