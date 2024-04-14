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
    public int res;
    
    public int sumOfLeftLeaves(TreeNode root) {
        res = 0;
        helper(root, -1);
        return res;
    }
    
    public void helper(TreeNode root, int dir) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            if (dir == 0) {
                res += root.val;
            }
        }
        helper(root.left, 0);
        helper(root.right, 1);
    }
}