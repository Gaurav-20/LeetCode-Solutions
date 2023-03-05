class Solution {
public:
    int passThePillow(int n, int time) {
        int cur = 1;
        bool dir = true;
        for (int t = 1; t <= time; t++) {
            if (dir) {
                cur++;
            } else {
                cur--;
            }
            if (cur == 1 || cur == n) {
                dir = !dir;
            }
        }
        return cur;
    }
};