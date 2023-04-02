class Solution {
public:
    int sign(int x) {
        if (x > 0) {
            return 1;
        } else if (x < 0) {
            return -1;
        } else {
            return 0;
        }
    }
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto asteroid : asteroids) {
            if (res.size() == 0) {
                res.push_back(asteroid);
            } else if (asteroid < 0 && res.back() > 0) {
                int asteroid1 = res.back();
                int asteroid2 = abs(asteroid);
                res.pop_back();
                if (asteroid1 == asteroid2) {
                    continue;
                } else if (asteroid1 > asteroid2) {
                    res.push_back(asteroid1);
                } else {
                    bool destroyed = false;
                    while (res.size() > 0 && sign(res.back()) != sign(asteroid)) {
                        if (res.back() < asteroid2) {
                            res.pop_back();
                        } else if (res.back() > asteroid2) {
                            destroyed = true;
                            break;
                        } else {
                            res.pop_back();
                            destroyed = true;
                            break;
                        }
                    }
                    if (!destroyed) {
                        res.push_back(asteroid);
                    }
                }
            } else {
                res.push_back(asteroid);
            }
        }
        return res;
    }
};