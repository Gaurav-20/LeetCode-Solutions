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
class Solution {
    
    public static int LEFT = -1;
    public static int RIGHT = 1;
    public int result = 0;
    
    public int longestZigZag(TreeNode root) {
        helper(root.left, 0, LEFT);
        helper(root.right, 0, RIGHT);
        return result;
    }
    
    private void helper(TreeNode root, int currentLength, int direction) {
        if (root == null) {
            result = Math.max(result, currentLength);
            return;
        }
        if (direction == LEFT) {
            helper(root.right, currentLength + 1, RIGHT);
            helper(root.left, 0, LEFT);
        } else {
            helper(root.left, currentLength + 1, LEFT);
            helper(root.right, 0, RIGHT);
        }
    }
}