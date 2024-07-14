class Solution {
    public String getSmallestString(String s) {
        char[] arr = s.toCharArray();
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] % 2 == arr[i - 1] % 2) {
                if (arr[i - 1] > arr[i]) {
                    char ch = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = ch;
                    break;
                }
            }
        }
        return String.valueOf(arr);
    }
}