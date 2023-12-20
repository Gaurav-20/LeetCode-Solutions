class Node {
    public String element;
    public double value;
    
    Node(String element, double value) {
        this.element = element;
        this.value = value;
    }
}

class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, List<Node>> graph = createGraph(equations, values);
        double[] result = new double[queries.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = findResult(graph, queries.get(i));
        }
        return result;
    }
    
    public Map<String, List<Node>> createGraph(List<List<String>> equations, double[] values) {
        Map<String, List<Node>> map = new HashMap<>();
        for (int i = 0; i < values.length; i++) {
            String src = equations.get(i).get(0);
            String dest = equations.get(i).get(1);
            List<Node> srcList = map.getOrDefault(src, new ArrayList<>());
            List<Node> destList = map.getOrDefault(dest, new ArrayList<>());
            srcList.add(new Node(dest, values[i]));
            destList.add(new Node(src, 1.0 / values[i]));;
            map.put(src, srcList);
            map.put(dest, destList);
        }
        return map;
    }
    
    public double findResult(Map<String, List<Node>> graph, List<String> query) {
        String src = query.get(0);
        String dest = query.get(1);
        if (graph.get(src) == null || graph.get(dest) == null) {
            return -1.0;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(src, 1.0));
        Map<String, Boolean> visited = new HashMap<>();
        visited.put(src, true);
        while (!queue.isEmpty()) {
            Node currNode = queue.poll();
            String curr = currNode.element;
            double value = currNode.value;
            if (curr.equals(dest)) {
                return value;
            }
            for (Node node : graph.get(curr)) {
                if (visited.get(node.element) == null) {
                    visited.put(node.element, true);
                    queue.offer(new Node(node.element, value * node.value));
                }
            }
        }
        return -1.0;
    }
}