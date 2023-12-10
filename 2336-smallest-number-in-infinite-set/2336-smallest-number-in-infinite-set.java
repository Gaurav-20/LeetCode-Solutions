class SmallestInfiniteSet {

    public boolean[] removed;

    public SmallestInfiniteSet() {
        removed = new boolean[1001];
    }
    
    public int popSmallest() {
        for (int i = 1; i <= 1000; i++) {
            if (!removed[i]) {
                removed[i] = true;
                return i;
            }
        }
        return -1;
    }
    
    public void addBack(int num) {
        removed[num] = false;
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */