class Solution {
public:
    string getActualString(string str) {
        string strActual;
        for (char& c: str) {
            if (c == '#') {
                if (strActual.size() > 0) {
                    strActual.pop_back();
                }
            } else {
                strActual += c;
            }
        }
        return strActual;
    }
    
    bool backspaceCompare(string s, string t) {
        return getActualString(s) == getActualString(t);
    }
};