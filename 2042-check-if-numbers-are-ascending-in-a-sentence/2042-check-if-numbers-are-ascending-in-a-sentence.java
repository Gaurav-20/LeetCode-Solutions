class Solution {
    public boolean areNumbersAscending(String s) {
        int prev = -1;
        for (String str: s.split(" ")) {
            if (isNumeric(str)) {
                Integer curr = Integer.valueOf(str);
                if (curr <= prev) {
                    return false;
                }
                prev = curr;
            }
        }
        return true;
    }
    
    public boolean isNumeric(String s) {
        for (char c: s.toCharArray()) {
            if (c < '0' || c > '9') {
                return false;
            }
        }
        return s.length() > 0;
    }
}