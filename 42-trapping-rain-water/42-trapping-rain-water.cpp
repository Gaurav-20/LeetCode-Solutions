class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n - 1, water = 0;

        int maxLeft = heights[left];
        int maxRight = heights[right];
 
        while (left < right) {
            if (heights[left] <= heights[right]) {
                left++;
                maxLeft = max(maxLeft, heights[left]);
                water += (maxLeft - heights[left]);
            } else {
                right--;
                maxRight = max(maxRight, heights[right]);
                water += (maxRight - heights[right]);
            }
        }
        return water;
    }
};