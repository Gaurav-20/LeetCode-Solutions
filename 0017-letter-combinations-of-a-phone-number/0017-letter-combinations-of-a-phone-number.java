class Solution {
    public List<String> letterCombinations(String digits) {
        String[] buttonToChars
            = new String[]{ "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        List<String> result = new ArrayList<>();
        if (digits.length() == 0) {
            return result;
        }
        result.add("");
        for (int i = 0; i < digits.length(); i++) {
            int currDigit = digits.charAt(i) - '0';
            String possibleChars = buttonToChars[currDigit];
            List<String> curr = new ArrayList<>();
            for (int j = 0; j < possibleChars.length(); j++) {
                String possibleChar = String.valueOf(possibleChars.charAt(j));
                for (String res : result) {
                    curr.add(res + possibleChar);
                }
            }
            result = curr;
        }
        return result;
    }
}