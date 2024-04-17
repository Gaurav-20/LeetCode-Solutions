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
    public String smallestFromLeaf(TreeNode root) {
        if (root == null) {
            return "";
        }
        return solve(root, "");
    }
    
    public String solve(TreeNode root, String suffix) {
        if (root == null) {
            return "";
        }
        suffix = (char)(root.val + 'a') + suffix;
        if (root.left == null && root.right == null) {
            return suffix;
        }
        String left = solve(root.left, suffix);
        String right = solve(root.right, suffix);
        if (left != "" && right != "") {
            return (left.compareTo(right) <= 0) ? left : right;
        }
        return (left != "") ? left : right;
    }
}