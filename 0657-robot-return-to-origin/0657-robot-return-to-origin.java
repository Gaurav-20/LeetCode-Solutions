class Solution {
    public boolean judgeCircle(String moves) {
        int xCoord = 0, yCoord = 0;
        for (char ch : moves.toCharArray()) {
            if (ch == 'L') {
                xCoord -= 1;
            } else if (ch == 'R') {
                xCoord += 1;
            } else if (ch == 'U') {
                yCoord += 1;
            } else {
                yCoord -= 1;
            }
        }
        return xCoord == 0 && yCoord == 0;
    }
}