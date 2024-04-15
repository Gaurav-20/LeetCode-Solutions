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
    public int totalSum;
    
    public int sumNumbers(TreeNode root) {
        totalSum = 0;
        recur(root, 0);
        return totalSum;
    }
    
    public void recur(TreeNode root, int pathSum) {
        if (root == null) {
            return;
        }
        pathSum = pathSum * 10 + root.val;
        if (root.left == null && root.right == null) {
            totalSum += pathSum;
            return;
        }
        recur(root.left, pathSum);
        recur(root.right, pathSum);
    }
}