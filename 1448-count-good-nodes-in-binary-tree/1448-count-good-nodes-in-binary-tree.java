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
    public int goodNodes(TreeNode root) {
        return solve(root, Integer.MIN_VALUE);
    }
    
    int solve(TreeNode root, int max) {
        if (root == null) {
            return 0;
        }
        if (root.val >= max) {
            return 1 + solve(root.left, root.val) + solve(root.right, root.val);
        }
        return solve(root.left, max) + solve(root.right, max);
    }
}