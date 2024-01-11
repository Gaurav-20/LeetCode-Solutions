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
    
    public int maxAncestorDiff(TreeNode root) {
        result = 0;
        solve(root, 1000000, -1);
        return result;
    }
    
    public void solve(TreeNode root, int min, int max) {
        if (root == null) {
            result = Math.max(result, max - min);
            return;
        }
        solve(root.left, Math.min(root.val, min), Math.max(root.val, max));
        solve(root.right, Math.min(root.val, min), Math.max(root.val, max));
        result = Math.max(result, max - min);
    }
}