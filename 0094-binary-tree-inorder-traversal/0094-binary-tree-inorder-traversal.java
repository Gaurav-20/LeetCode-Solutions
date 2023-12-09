/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class StackNode {
    public TreeNode treeNode;
    public int state;
    
    StackNode(TreeNode treeNode, int state) {
        this.treeNode = treeNode;
        this.state = state;
    }
    
    public TreeNode getTreeNode() {
        return treeNode;
    }
    
    public int getState() {
        return state;
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<StackNode> stack = new Stack<>();
        stack.push(new StackNode(root, 0));
        while (!stack.empty()) {
            TreeNode curr = stack.peek().getTreeNode();
            int state = stack.peek().getState();
            stack.pop();
            if (curr == null || state == 3) {
                continue;
            }
            stack.push(new StackNode(curr, state + 1));
            if (state == 0) {
                stack.push(new StackNode(curr.left, 0));
            } else if (state == 1) {
                result.add(curr.val);
            } else {
                stack.push(new StackNode(curr.right, 0));
            }
        }
        return result;
    }
}