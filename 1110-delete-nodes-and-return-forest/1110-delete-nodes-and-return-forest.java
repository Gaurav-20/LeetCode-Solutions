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
    public List<TreeNode> result;
    public Set<Integer> nodesToDelete;
    
    public List<TreeNode> delNodes(TreeNode root, int[] toDelete) {
        this.result = new ArrayList<>();
        this.nodesToDelete = new HashSet<>();
        for (int node: toDelete) {
            nodesToDelete.add(node);
        }
        dfs(root, true);
        return result;
    }
    
    public boolean dfs(TreeNode root, boolean flag) {
        if (root == null) {
            return false;
        }
        boolean ret = false;
        if (nodesToDelete.contains(root.val)) {
            ret = true;
            flag = false;
        }
        if (dfs(root.left, ret)) {
            root.left = null;
        }
        if (dfs(root.right, ret)) {
            root.right = null;
        }
        if (flag) {
            result.add(root);
        }
        return ret;
    }
}