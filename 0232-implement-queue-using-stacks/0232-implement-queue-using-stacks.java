class MyQueue {
    
    public Stack<Integer> stack;

    public MyQueue() {
        stack = new Stack<>();
    }
    
    public void push(int x) {
        Stack<Integer> aux = new Stack<>();
        while (stack.size() > 0) {
            aux.add(stack.pop());
        }
        stack.add(x);
        while (aux.size() > 0) {
            stack.add(aux.pop());
        }
    }
    
    public int pop() {
        return stack.pop();
    }
    
    public int peek() {
        return stack.peek();
    }
    
    public boolean empty() {
        return stack.size() == 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */