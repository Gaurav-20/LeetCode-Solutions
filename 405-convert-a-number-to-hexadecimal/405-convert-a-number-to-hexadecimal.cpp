string HEX = "0123456789abcdef";

class Solution {
public:
    
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        unsigned int n = (unsigned int) num;
        string res = "";
        while (n > 0) {
            res = HEX[(n & 0xf)] + res;
            n >>= 4;
        }
        return res;
    }
};