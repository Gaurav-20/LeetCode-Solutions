class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        return Math.max(find(red, blue), find(blue, red));
    }
    
    public int find(int color1, int color2) {
        int rows = 0;
        for (int i = 1; ; i += 2) {
            if (color1 < i) {
                break;
            }
            color1 -= i;
            rows += 1;
            if (color2 < i + 1) {
                break;
            }
            color2 -= i + 1;
            rows += 1;
        }
        return rows;
    }
}