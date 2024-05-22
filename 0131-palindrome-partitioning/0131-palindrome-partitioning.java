class Solution {
    public List<List<String>> result;
    public List<String> part;
    
    public List<List<String>> partition(String s) {
        int n = s.length();
        result = new ArrayList<>();
        part = new ArrayList<>();
        solve(s, 0, n);
        return result;
    }
    
    public void solve(String s, int i, int n) {
        if (i == n) {
            result.add(new ArrayList<>(part));
            return;
        }
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                part.add(s.substring(i, j + 1));
                solve(s, j + 1, n);
                part.remove(part.size() - 1);
            }
        }
    }
    
    public boolean isPalindrome(String s, int low, int high) {
        while (low <= high) {
            if (s.charAt(low) != s.charAt(high)) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
}