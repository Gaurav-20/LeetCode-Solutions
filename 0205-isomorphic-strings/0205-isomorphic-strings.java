class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> map = new HashMap<>();
        Set<Character> assigned = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            char cs = s.charAt(i);
            char ct = t.charAt(i);
            if (map.get(cs) == null) {
                if (assigned.contains(ct)) {
                    return false;
                }
                map.put(cs, ct);
                assigned.add(ct);
            } else {
                if (map.get(cs) != ct) {
                    return false;
                }
            }
        }
        return true;
    }
}