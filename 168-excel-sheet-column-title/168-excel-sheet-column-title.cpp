class Solution {
public:
    string convertToTitle(int columnNumber) {
        return (columnNumber == 0) ? "" : 
        convertToTitle((columnNumber - 1) / 26) + (char) ((columnNumber - 1) % 26 + 'A');
    }
};