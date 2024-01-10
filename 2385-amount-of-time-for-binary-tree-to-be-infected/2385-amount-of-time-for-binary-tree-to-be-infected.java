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
    
    public Map<Integer, List<Integer>> graph;
    
    public int amountOfTime(TreeNode root, int start) {
        this.graph = new HashMap<>();
        generateGraph(root);
        return findAmountOfTime(start);
    }
    
    public void generateGraph(TreeNode root) {
        if (root == null) {
            return;
        }
        if (graph.get(root.val) == null) {
            graph.put(root.val, new ArrayList<>());
        }
        if (root.left != null) {
            if (graph.get(root.left.val) == null) {
                graph.put(root.left.val, new ArrayList<>());
            }
            graph.get(root.val).add(root.left.val);
            graph.get(root.left.val).add(root.val);
        }
        if (root.right != null) {
            if (graph.get(root.right.val) == null) {
                graph.put(root.right.val, new ArrayList<>());
            }
            graph.get(root.val).add(root.right.val);
            graph.get(root.right.val).add(root.val);
        }
        generateGraph(root.left);
        generateGraph(root.right);
    }
    
    public int findAmountOfTime(int start) {
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        queue.add(start);
        visited.add(start);
        int timer = -1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                Integer curr = queue.poll();
                for (Integer neigh : graph.get(curr)) {
                    if (!visited.contains(neigh)) {
                        queue.offer(neigh);
                        visited.add(neigh);
                    }
                }
            }
            timer++;
        }
        return timer;
    }
}