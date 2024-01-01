class StockSpanner {
    
    private Stack<Pair<Integer, Integer>> stack;
    
    public StockSpanner() {
        stack = new Stack<>();
    }
    
    public int next(int price) {
        int result = 1;
        while (!stack.isEmpty() && stack.peek().getKey() <= price) {
            result += stack.peek().getValue();
            stack.pop();
        }
        stack.add(new Pair(price, result));
        return result;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */