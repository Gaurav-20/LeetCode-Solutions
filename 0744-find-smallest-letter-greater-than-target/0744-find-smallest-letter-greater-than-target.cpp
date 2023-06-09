class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) {
            return letters[0];
        }
        for (char& letter: letters) {
            if (letter > target) {
                return letter;
            }
        }
        return ' ';
    }
};