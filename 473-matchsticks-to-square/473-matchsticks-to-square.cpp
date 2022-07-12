class Solution {
public:
    vector<int> matchsticks;
    int n;
    bool vis[16];

    bool canMakeSquare(int currentSum, int oneSideLength, int totalSides, int idx = 0) {
        if (totalSides == 0) {
            return true;
        }
        if (currentSum == oneSideLength) {
            return canMakeSquare(0, oneSideLength, totalSides - 1, 0);
        }
        if (idx >= n) {
            return false;
        }
        for (int i = idx; i < n; i++) {
            if (!vis[i]) {
                if (currentSum + matchsticks[i] <= oneSideLength) {
                    vis[i] = true;
                    if (canMakeSquare(currentSum + matchsticks[i], 
                                      oneSideLength, totalSides, i + 1)) {
                        return true;
                    }
                    vis[i] = false;
                }
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        this->matchsticks = matchsticks;
        n = matchsticks.size();
        memset(vis, false, sizeof(vis));
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) {
            return false;
        }
        int oneSideLength = sum / 4;
        int totalSides = 4;
        return canMakeSquare(0, oneSideLength, totalSides);
    }
};