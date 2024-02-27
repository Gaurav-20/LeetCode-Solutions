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
    
    public int result;
    
    public int solve(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = solve(root.left);
        int right = solve(root.right);
        this.result = Math.max(this.result, left + right);
        return 1 + Math.max(left, right);
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        this.result = 0;
        solve(root);
        return this.result;
    }
}