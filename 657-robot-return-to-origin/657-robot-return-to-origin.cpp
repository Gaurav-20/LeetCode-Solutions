class Solution {
public:
    bool judgeCircle(string moves) {
        int count = 0;
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'L') {
                x--;
            } else if (c == 'R') {
                x++;
            } else if (c == 'U') {
                y--;
            } else {
                y++;
            }
        }
        return x == 0 && y == 0;
    }
};