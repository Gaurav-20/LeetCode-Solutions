class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenNeedle = needle.size();
        int lenHaystack = haystack.size();
        if (lenHaystack < lenNeedle) {
            return -1;
        } else if (lenHaystack == lenNeedle) {
            return (haystack == needle) ? 0 : -1;
        } else {
            string temp = "";
            for (int i = 0; i < lenNeedle; i++) {
                temp.push_back(haystack[i]);
            }
            if (temp == needle) {
                return 0;
            }
            for (int i = lenNeedle; i < lenHaystack; i++) {
                temp.erase(0, 1);
                temp.push_back(haystack[i]);
                if (temp == needle) {
                    return i - lenNeedle + 1;
                }
            }
        }
        return -1;
    }
};