class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int index = 0;
        string res = "";
        for (string& num: nums) {
            res += ((num[index++] - '0') ^ 1) + '0';
        }
        return res;
    }
};