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
    
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return 0;
        }
        sumUp(root, 0, targetSum);
        pathSum(root.left, targetSum);
        pathSum(root.right, targetSum);
        return result;
    }
    
    public void sumUp(TreeNode root, long sum, int targetSum) {
        if (root == null) {
            return;
        }
        sum += root.val;
        if (sum == targetSum) {
            result++;
        }
        sumUp(root.left, sum, targetSum);
        sumUp(root.right, sum, targetSum);
    }
}