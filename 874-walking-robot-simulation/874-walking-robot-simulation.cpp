class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3
        int d = 0;
        int posX = 0, posY = 0, res = 0;
        vector<vector<int>> dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        map<vector<int>, bool> mp;
        for (auto it : obstacles) {
            mp[it] = true;
        }
        for (int cmd : commands) {
            if (cmd == -2) {
                d = (d + 3) % 4;
            } else if (cmd == -1) {
                d = (d + 1) % 4;
            } else {
                int moves = cmd;
                while (moves-- && !mp[{ posX + dir[d][0], posY + dir[d][1] }]) {
                    posX += dir[d][0];
                    posY += dir[d][1];
                }
                res = max(res, (posX * posX + posY * posY));
            }
        }
        return res;
    }
};