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
    public int findTilt(TreeNode root) {
        int[] res = solve(root);
        return res[0];
    }
    
    public int[] solve(TreeNode root) {
        if (root == null) {
            return new int[]{ 0, 0 };
        }
        int[] leftRes = solve(root.left);
        int[] rightRes = solve(root.right);
        int tilt = Math.abs(leftRes[1] - rightRes[1]);
        return new int[]{ leftRes[0] + rightRes[0] + tilt, leftRes[1] + rightRes[1] + root.val };
    }
}