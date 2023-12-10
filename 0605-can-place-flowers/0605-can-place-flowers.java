class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int len = flowerbed.length;
        if (len == 1) {
            return (n == 0) || (n == 1 && flowerbed[0] != 1);
        }
        if (len < n) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                if (flowerbed[i] + flowerbed[i + 1] == 0) {
                    n--;
                    i++;
                }
            } else if (i == len - 1) {
                if (flowerbed[i - 1] + flowerbed[i] == 0) {
                    n--;
                    i++;
                }
            } else {
                if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                    n--;
                    i++;
                }
            }
        }
        return n <= 0;
    }
}