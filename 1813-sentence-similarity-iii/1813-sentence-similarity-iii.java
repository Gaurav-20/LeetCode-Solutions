class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] sentArr1 = sentence1.split(" ");
        String[] sentArr2 = sentence2.split(" ");
        int prefixLen = longestCommonPrefix(sentArr1, sentArr2);
        int suffixLen = longestCommonSuffix(sentArr1, sentArr2);
        return (prefixLen + suffixLen) >= Math.min(sentArr1.length, sentArr2.length);
    }
    
    public int longestCommonPrefix(String[] strs1, String[] strs2) {
        int it1 = 0, it2 = 0, result = 0;;
        while (it1 < strs1.length && it2 < strs2.length) {
            if (strs1[it1].equals(strs2[it2])) {
                result += 1;
                it1 += 1;
                it2 += 1;
            } else {
                break;
            }
        }
        return result;
    }
    
    public int longestCommonSuffix(String[] strs1, String[] strs2) {
        int it1 = strs1.length - 1, it2 = strs2.length - 1, result = 0;;
        while (it1 >= 0 && it2 >= 0) {
            if (strs1[it1].equals(strs2[it2])) {
                result += 1;
                it1 -= 1;
                it2 -= 1;
            } else {
                break;
            }
        }
        return result;
    }
}