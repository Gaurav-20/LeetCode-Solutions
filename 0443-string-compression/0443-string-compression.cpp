class Solution {
public:
    int numOfDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int res = 0;
        while (n > 0) {
            res++;
            n /= 10;
        }
        return res;
    }
    
    int compress(vector<char>& chars) {
        int newLen = 0;
        int currLen = size(chars);
        if (currLen == 1) {
            return 1;
        }
        int i = 0;
        int it = 0;
        while (i < currLen) {
            int count = 1;
            char c = chars[i];
            while (i < currLen - 1 && (chars[i] == chars[i + 1])) {
                count++;
                i++;
            }
            chars[it++] = c;
            int numDigits = numOfDigits(count);
            if (count != 1) {
                string strCount = to_string(count);
                for (char x : strCount) {
                    chars[it++] = x;
                }
                count += numDigits;
            }
            i++;
        }
        for (int i = it; i < currLen; i++) {
            chars.pop_back();
        }
        return it;
    }
};