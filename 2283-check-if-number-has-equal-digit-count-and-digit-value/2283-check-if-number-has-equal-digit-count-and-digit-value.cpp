class Solution {
public:
    bool digitCount(string num) {
        vector<int> hash(10, 0);
        for (char& c : num) {
            hash[c - '0']++;
        }
        for (int i = 0; i < num.size(); i++) {
            if (num[i] - '0' != hash[i]) {
                return false;
            }
        }
        return true;
    }
};