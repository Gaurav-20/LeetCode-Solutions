class Solution {
    public String maximumOddBinaryNumber(String s) {
        int oneCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                oneCount += 1;
            }
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < oneCount - 1; i++) {
            builder.append('1');
        }
        for (int i = oneCount; i < s.length(); i++) {
            builder.append('0');
        }
        builder.append('1');
        return builder.toString();
    }
}