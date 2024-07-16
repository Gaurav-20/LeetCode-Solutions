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
    public String getDirections(TreeNode root, int startValue, int destValue) {
        TreeNode pathRoot = findLca(root, startValue, destValue);
        StringBuilder pathFrom = new StringBuilder();
        StringBuilder pathTo = new StringBuilder();
        dfs(pathRoot, startValue, pathFrom, true);
        dfs(pathRoot, destValue, pathTo, false);
        return pathFrom.toString() + pathTo.toString();
    }
    
    public TreeNode findLca(TreeNode root, int x, int y) {
        if (root == null || root.val == x || root.val == y) {
            return root;
        }
        TreeNode l = findLca(root.left, x, y);
        TreeNode r = findLca(root.right, x, y);
        if (l == null) {
            return r;
        }
        if (r == null) {
            return l;
        }
        return root;
    }
    
    public boolean dfs(TreeNode root, int val, StringBuilder path, boolean reverse) {
        if (root == null) {
            return false;
        }
        if (root.val == val) {
            return true;
        }
        path.append(reverse ? 'U' : 'L');
        if (dfs(root.left, val, path, reverse)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);
        path.append(reverse ? 'U' : 'R');
        if (dfs(root.right, val, path, reverse)) {
            return true;
        }
        path.deleteCharAt(path.length() - 1);
        return false;
    }
}