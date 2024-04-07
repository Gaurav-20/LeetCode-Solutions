class Solution {
    public String getSmallestString(String s, int k) {
        StringBuilder builder = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (k > 0) {
                for (char c = 'a'; c <= 'z'; c++) {
                    int dist = charDistance(ch, c);
                    if (dist <= k) {
                        k -= dist;
                        builder.append(c);
                        break;
                    }
                }
            } else {
                builder.append(ch);
            }
        }
        return builder.toString();
    }
    
    public int charDistance(char x, char y) {
        return Math.min((x - y + 26) % 26, (y - x + 26) % 26);
    }
}