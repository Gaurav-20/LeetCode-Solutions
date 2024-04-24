class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> result = new ArrayList<>();
        Set<String> set = new HashSet<>();
        set.addAll(wordDict);
        partition(s, set, 0, "", result);
        return result;
    }

    public static void partition(String s, Set<String> set, int idx, String str, List<String> result) {
        if (idx == s.length()) {
            result.add(str.stripTrailing());
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (set.contains(s.substring(idx, i + 1))) {
                partition(s, set, i + 1, str + s.substring(idx, i + 1) + " ", result);
            }
        }
    }
}