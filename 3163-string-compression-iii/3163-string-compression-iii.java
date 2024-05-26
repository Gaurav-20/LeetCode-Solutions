class Solution {
    public String compressedString(String word) {
        StringBuilder builder = new StringBuilder();
        int n = word.length();
        for (int i = 0; i < n; i++) {
            char curr = word.charAt(i);
            int counter = 0;
            while (i < n && word.charAt(i) == curr && counter < 9) {
                counter += 1;
                i += 1;
            }
            builder.append(String.valueOf(counter) + curr);
            if (i < n) {
                i -= 1;
            }
        }
        return builder.toString();
    }
}