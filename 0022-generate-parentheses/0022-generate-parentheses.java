class Solution {
    public List<String> result;
    
    public List<String> generateParenthesis(int n) {
        result = new ArrayList<>();
        solve("", 0, 0, n);
        return result;
    }
    
    public void solve(String curr, int open, int close, int n) {
        if (open == n && close == n) {
            result.add(curr);
            return;
        }
        if (open < n) {
            solve(curr + "(", open + 1, close, n);
        }
        if (open > close) {
            solve(curr + ")", open, close + 1, n);
        }
    }
}