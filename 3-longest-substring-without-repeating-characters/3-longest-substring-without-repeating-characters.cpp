class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> rangeFreq;
        int low = 0, high = 0;
        int res = 0;
        int count = 0;
        int len = s.size();
        while (high < len) {
            if (rangeFreq[s[high]] == 0) {
                count++;
            } else {
                while (s[high] != s[low]) {
                    rangeFreq[s[low]]--;
                    low++;
                    count--;
                }
                rangeFreq[s[low]]--;
                low++;
            }
            res = max(res, count);
            rangeFreq[s[high]]++;
            high++;
        }
        res = max(res,count);
        return res;
    }
};