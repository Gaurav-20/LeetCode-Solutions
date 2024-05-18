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
    public int moves;
    
    public int distributeCoins(TreeNode root) {
        moves = 0;
        solve(root);
        return moves;
    }
    
    public int solve(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = solve(root.left);
        int right = solve(root.right);
        int balance = root.val + left + right - 1;
        moves += Math.abs(balance);
        return balance;
    }
}