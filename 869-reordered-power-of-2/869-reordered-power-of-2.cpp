class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(str.begin(), str.end());
        for (int i = 0; i < 32; i++) {
            string powerOfTwo = to_string(1 << i);
            sort(powerOfTwo.begin(), powerOfTwo.end());
            if (str == powerOfTwo) {
                return true;
            }
        }
        return false;
    }
};