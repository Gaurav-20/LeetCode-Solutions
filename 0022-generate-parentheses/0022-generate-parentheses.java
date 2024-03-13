class Node {
    public int left;
    public int right;
    public String str;
    
    Node(int left, int right, String str) {
        this.left = left;
        this.right = right;
        this.str = str;
    }
}

class Solution {
    public List<String> result;
    
    public List<String> generateParenthesis(int n) {
        result = new ArrayList<>();
        int left = 0, right = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(left, right, ""));
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (node.str.length() == 2 * n) {
                result.add(node.str);
            }
            if (node.left < n) {
                queue.offer(new Node(node.left + 1, node.right, node.str + "("));
            }
            if (node.right < node.left) {
                queue.offer(new Node(node.left, node.right + 1, node.str + ")"));
            }
        }
        return result;
    }
    
    // public void solve(String curr, int open, int close, int n) {
    //     if (open == n && close == n) {
    //         result.add(curr);
    //         return;
    //     }
    //     if (open < n) {
    //         solve(curr + "(", open + 1, close, n);
    //     }
    //     if (open > close) {
    //         solve(curr + ")", open, close + 1, n);
    //     }
    // }
}