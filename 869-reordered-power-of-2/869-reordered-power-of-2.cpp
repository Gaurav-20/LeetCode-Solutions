class Solution {
public:
    bool isPowerOfTwo(int n) {
        return __builtin_popcount(n) == 1;
    }
    
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(str.begin(), str.end());
        do {
            if (str[0] != '0' && isPowerOfTwo(stoi(str))) {
                return true;
            }
        } while (next_permutation(str.begin(), str.end()));
        return false;
    }
};