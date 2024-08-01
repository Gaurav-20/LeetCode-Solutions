class Solution {
    public int countSeniors(String[] details) {
        int seniors = 0;
        for (String detail: details) {
            char ch1 = detail.charAt(11), ch2 = detail.charAt(12);
            if (ch1 > '6' || (ch1 == '6' && ch2 > '0')) {
                seniors += 1;
            }
        }
        return seniors;
    }
}