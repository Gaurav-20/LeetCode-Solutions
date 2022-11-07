class Solution {
public:
    int maximum69Number(int num) {
        string number = to_string(num);
        for (char& n : number) {
            if (n == '6') {
                n = '9';
                break;
            }
        }
        return stoi(number);
    }
};