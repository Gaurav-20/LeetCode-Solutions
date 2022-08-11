class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3
        int direction = 0;
        int posX = 0, posY = 0;
        int res = 0;
        map<vector<int>, bool> mp;
        for (auto it : obstacles) {
            mp[it] = true;
        }
        for (auto cmd : commands) {
            if (cmd == -2) {
                direction = (direction + 3) % 4;
            } else if (cmd == -1) {
                direction = (direction + 1) % 4;
            } else {
                int moves = cmd;
                if (direction == 0) {
                    while (moves > 0) {
                        if (mp[{ posX, posY + 1 }]) {
                            break;
                        }
                        posY++;
                        moves--;
                    }
                } else if (direction == 1) {
                    while (moves > 0) {
                        if (mp[{ posX + 1, posY }]) {
                            break;
                        }
                        posX++;
                        moves--;
                    }
                } else if (direction == 2) {
                    while (moves > 0) {
                        if (mp[{ posX, posY - 1 }]) {
                            break;
                        }
                        posY--;
                        moves--;
                    }
                } else {
                    while (moves > 0) {
                        if (mp[{ posX - 1, posY }]) {
                            break;
                        }
                        posX--;
                        moves--;
                    }
                }
                res = max(res, (posX * posX + posY * posY));
            }
        }
        return res;
    }
};