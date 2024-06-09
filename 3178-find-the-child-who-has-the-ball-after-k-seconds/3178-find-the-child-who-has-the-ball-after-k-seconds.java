class Solution {
    public int numberOfChild(int n, int k) {
        int ptr = 0, dir = 1;
        for (int i = 0; i < k; i++) {
            if (ptr == 0) {
                dir = 1;
            }
            if (ptr == n - 1) {
                dir = -1;
            }
            ptr += dir;
        }
        return ptr;
    }
}