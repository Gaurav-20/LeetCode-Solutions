class Solution {
    public int passThePillow(int n, int time) {
        int pillow = 1, dir = 1;
        for (int i = 1; i <= time; i++) {
            pillow += dir;
            if (pillow == 1 || pillow == n) {
                dir *= -1;
            }
        }
        return pillow;
    }
}