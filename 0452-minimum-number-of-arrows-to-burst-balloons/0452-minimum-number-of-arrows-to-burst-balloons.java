class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        int arrows = 0, end = -1;
        for (int[] point : points) {
            if (end == -1 || end < point[0]) {
                end = point[1];
                arrows++;
            } else {
                end = Math.min(end, point[1]);
            }
        }
        return arrows;
    }
}