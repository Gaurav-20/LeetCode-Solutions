class Solution {
public:
    void append(string word, char separator, vector<string>& result) {
        string temp = "";
        for (char c: word) {
            if (c == separator) {
                if (temp != "") {
                    result.push_back(temp);
                    temp = "";
                }
            } else {
                temp += c;
            }
        }
        if (temp != "") {
            result.push_back(temp);
        }
    }
    
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        for (string word: words) {
            append(word, separator, result);
        }
        return result;
    }
};