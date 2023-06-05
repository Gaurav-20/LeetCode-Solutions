class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int len = coordinates.size();
        if (len == 2) {
            return true;
        }
        for (int i = 2; i < len; i++) {
            int x0 = coordinates[i - 2][0];
            int y0 = coordinates[i - 2][1];
            int x1 = coordinates[i - 1][0];
            int y1 = coordinates[i - 1][1];
            int x2 = coordinates[i][0];
            int y2 = coordinates[i][1];
            if ((y1 - y0) * (x2 - x1) != (x1 - x0) * (y2 - y1)) {
                return false;
            }
        }
        return true;
    }
};