/*
    i, j => i, j
    0, 0 => 0, 0 - we can't select both zeros as they give same output
    0, 1 => 1, 1
    1, 0 => 1, 1
    1, 1 => 1, 0
*/

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        // we just need to check if both s and target have atlease one 1
        bool sContainsOne = false, targetContainsOne = false;
        for (int i = 0; i < s.size(); i++) {
            sContainsOne |= s[i] == '1';
            targetContainsOne |= target[i] == '1';
        }
        return s == target || (sContainsOne && targetContainsOne);
    }
};