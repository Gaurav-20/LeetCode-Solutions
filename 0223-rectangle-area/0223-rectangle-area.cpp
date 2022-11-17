class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaOfA = (ay2 - ay1) * (ax2 - ax1);
        int areaOfB = (by2 - by1) * (bx2 - bx1);
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int bottom = max(ay1, by1);
        int top = min(ay2, by2);
        int overlapArea = 0;
        if (right > left && top > bottom) {
             overlapArea = (right - left) * (top - bottom);
        }
        return areaOfA + areaOfB - overlapArea;
    }
};