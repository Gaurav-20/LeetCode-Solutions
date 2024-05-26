class Solution {
    public String[] morse = new String[] {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    
    public int uniqueMorseRepresentations(String[] words) {
        Set<String> set = new HashSet<>();
        for (String word : words) {
            StringBuilder builder = new StringBuilder();
            for (char ch : word.toCharArray()) {
                builder.append(morse[ch - 'a']);
            }
            set.add(builder.toString());
        }
        return (int) set.size();
    }
}