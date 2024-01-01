class Solution {
    public int findContentChildren(int[] greed, int[] cookieSize) {
        Arrays.sort(greed);
        Arrays.sort(cookieSize);
        int result = 0, i = 0, j = 0;
        while (i < greed.length && j < cookieSize.length) {
            if (cookieSize[j] >= greed[i]) {
                result++;
                i++;
            }
            j++;
        }
        return result;
    }
}