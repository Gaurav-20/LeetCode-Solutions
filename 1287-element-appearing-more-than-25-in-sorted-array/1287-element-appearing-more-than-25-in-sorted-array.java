class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            int curr = arr[i], count = 0;
            while (i < n && curr == arr[i]) {
                count++;
                i++;
            }
            if (count > n / 4) {
                return curr;
            }
            if (i < n) {
                i--;
            }
        }
        return -1;
    }
}