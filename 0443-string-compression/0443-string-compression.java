class Solution {
    public int compress(char[] chars) {
        int len = chars.length, iter = 0;
        for (int i = 0; i < len; i++) {
            char c = chars[i];
            int count = 0;
            while (i < len && chars[i] == c) {
                count++;
                i++;
            }
            if (i < len) {
                i--;
            }
            chars[iter++] = c;
            if (count > 1) {
                String strCount = String.valueOf(count);
                for (int k = 0; k < strCount.length(); k++) {
                    chars[iter++] = strCount.charAt(k);
                }
            }
        }
        return iter;
    }
}