class Solution {
    public String reversePrefix(String word, char ch) {
        char[] arr = word.toCharArray();
        int end = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == ch) {
                end = i;
                break;
            }
        }
        if (end == -1) {
            return word;
        }
        return reverse(arr, end);
    }
    
    public String reverse(char[] arr, int end) {
        int start = 0;
        while (start < end) {
            char c = arr[start];
            arr[start] = arr[end];
            arr[end] = c;
            start += 1;
            end -= 1;
        }
        return String.valueOf(arr);
    }
}