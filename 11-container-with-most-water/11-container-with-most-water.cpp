class Solution {
public:
    int maxArea(vector<int>& heights) {
        int water = 0;
        int low = 0, high = heights.size() - 1;
        while (low < high) {
            int height = min(heights[low], heights[high]);
            water = max(water, (high - low) * height);
            while (heights[low] <= height && low < high) {
                low++;
            }
            while (heights[high] <= height && low < high) {
                high--;
            }
        }
        return water;
    }
};