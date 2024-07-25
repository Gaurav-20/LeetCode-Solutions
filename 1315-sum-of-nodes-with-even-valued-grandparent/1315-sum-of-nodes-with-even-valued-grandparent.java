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
    public int result = 0;
    
    public int sumEvenGrandparent(TreeNode root) {
        solve(root);
        return result;
    }
    
    public void solve(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.val % 2 == 0) {
            if (root.left != null) {
                if (root.left.left != null) {
                    result += root.left.left.val;
                }
                if (root.left.right != null) {
                    result += root.left.right.val;
                }
            }
            if (root.right != null) {
                if (root.right.left != null) {
                    result += root.right.left.val;
                }
                if (root.right.right != null) {
                    result += root.right.right.val;
                }
            }
        }
        solve(root.left);
        solve(root.right);
    }
}