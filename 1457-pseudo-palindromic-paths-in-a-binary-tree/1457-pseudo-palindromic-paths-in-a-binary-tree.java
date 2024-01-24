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
    public int[] freq;
    
    public int pseudoPalindromicPaths(TreeNode root) {
        this.result = 0;
        this.freq = new int[10];
        solve(root);
        return result;
    }
    
    public void solve(TreeNode root) {
        if (root == null) {
            return;
        }
        freq[root.val] += 1;
        if (root.left == null && root.right == null) {
            this.result += hasAtmostOneOddFreqVal(freq) ? 1 : 0;
        }
        solve(root.left);
        solve(root.right);
        freq[root.val] -= 1;
    }
    
    public boolean hasAtmostOneOddFreqVal(int[] freq) {
        int count = 0;
        for (int i = 0; i < 10; i++) {
            if (freq[i] % 2 == 1) {
                count += 1;
            }
        }
        return count <= 1;
    }
}