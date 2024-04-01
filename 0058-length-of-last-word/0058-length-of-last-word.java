class Solution {
    public int lengthOfLastWord(String s) {
        String[] arr = s.trim().split("\\s+");
        return arr[arr.length - 1].length();
    }
}