class Solution {
public:
    int binaryToInt(string s) {
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            res = (res * 2) + (s[i] - '0');
        }
        return res;
    }
    
    string intToBinary(int num, int n) {
        string res = "";
        while (num > 0) {
            res += ((num % 2) + '0');
            num /= 2;
        }
        while (res.size() < n) {
            res += '0';
        }
        return res;
    }
    
    vector<int> convertToInteger(vector<string>& nums) {
        vector<int> res;
        for (string num: nums) {
            res.push_back(binaryToInt(num));
        }
        return res;
    }
    
    int smallestMissing(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num: nums) {
            mp[num]++;
        }
        for (int i = 0; ; i++) {
            if (mp[i] == 0) {
                return i;
            }
        }
        return -1;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> integerArr = convertToInteger(nums);
        int smallestMissingNumber = smallestMissing(integerArr);
        return intToBinary(smallestMissingNumber, nums[0].size());
    }
};