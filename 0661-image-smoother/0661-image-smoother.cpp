int dirX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dirY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> smoothenedImage(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currSum = img[i][j], count = 1;
                for (int move = 0; move < 8; move++) {
                    int x = i + dirX[move], y = j + dirY[move];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    currSum += img[x][y];
                    count++;
                }
                smoothenedImage[i][j] = currSum / count;
            }
        }
        return smoothenedImage;
    }
};