class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToInt = {
            { 'I' , 1 },
            { 'V' , 5 },
            { 'X' , 10 },
            { 'L' , 50 },
            { 'C' , 100 },
            { 'D' , 500 },
            { 'M' , 1000 }
        };
                                   
       int res = romanToInt[s.back()];
       for (int i = s.size() - 2; i >= 0; i--) {
           int curr = romanToInt[s[i]];
           int prev = romanToInt[s[i + 1]];
           if (curr < prev) {
               res -= curr;
           } else {
               res += curr;
           }
       }
       return res;
    }
};