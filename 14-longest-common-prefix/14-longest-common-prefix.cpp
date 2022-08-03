class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int len = strs.size();
        int minLen = INT_MAX;
        for (int i = 0; i < len; i++) {
            minLen = min(minLen, (int) strs[i].size());
        }
        int index = 0;
        while (true) {
            if (index >= minLen) {
                break;
            }
            char curr = strs[0][index];
            bool flag = true;
            for (int i = 1; i < len; i++) {
                if (strs[i][index] != curr) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
            res += curr;
            index++;
        }
        return res;
    }
};