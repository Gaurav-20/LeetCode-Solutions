class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +"); // trim for trimming begin and end space, split to remove in between space
        Collections.reverse(Arrays.asList(words));
        return String.join(" ", words);
    }
}