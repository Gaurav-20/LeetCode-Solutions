#define UNINITIALIZED -1

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrows = 0, end = UNINITIALIZED;
        for (auto& pt : points) {
            if (end == UNINITIALIZED || end < pt[0]) {
                end = pt[1];
                arrows++;
            } else {
                end = min(end, pt[1]);
            }
        }
        return arrows;
    }
};