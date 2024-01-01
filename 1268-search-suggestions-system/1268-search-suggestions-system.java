class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        PriorityQueue<String> pq = new PriorityQueue<>(3, (s1, s2) -> s1.compareTo(s2)); 
        List<List<String>> result = new ArrayList<>();
        for (int i = 1; i <= searchWord.length(); i++) {
            String curr = searchWord.substring(0, i);
            for (String product : products) {
                if (product.startsWith(curr)) {
                    pq.offer(product);
                }
            }
            List<String> currResult = new ArrayList<>();
            for (int j = 0; j < 3; j++) {
                if (pq.peek() != null) {
                    currResult.add(pq.poll());
                }
            }
            pq.clear();
            result.add(currResult);
        }
        return result;
    }
}