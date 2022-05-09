string buttonToChars[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int len = digits.size();
        if (len == 0) {
            return result;
        }
        result.push_back("");
        for (char& digit : digits) {
            vector<string> curr;
            string possibleChars = buttonToChars[digit - '0'];
            for (char& possibleChar : possibleChars) {
                for (string res : result) {
                    curr.push_back(res + possibleChar);
                }
            }
            result = curr;
        }
        return result;
    }
};