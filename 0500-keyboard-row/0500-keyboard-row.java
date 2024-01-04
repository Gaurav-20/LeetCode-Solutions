class Solution {
    
    public static String TOP_ROW_CHARS = "qwertyuiop";
    public static String MIDDLE_ROW_CHARS = "asdfghjkl";
    public static String BOTTOM_ROW_CHARS = "zxcvbnm";
    
    public String[] findWords(String[] words) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            String word = words[i].toLowerCase();
            if (canBeTypedByRow(word, TOP_ROW_CHARS) ||
                canBeTypedByRow(word, MIDDLE_ROW_CHARS) ||
                canBeTypedByRow(word, BOTTOM_ROW_CHARS)) {
                result.add(words[i]);
            }
        }
        return result.toArray(new String[0]);
    }
    
    boolean canBeTypedByRow(String word, String row) {
        for (int i = 0; i < word.length(); i++) {
            if (row.indexOf(word.charAt(i)) == -1) {
                return false;
            }
        }
        return true;
    }
}