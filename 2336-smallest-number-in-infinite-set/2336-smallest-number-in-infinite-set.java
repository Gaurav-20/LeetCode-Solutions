class SmallestInfiniteSet {

    public boolean[] present;

    public SmallestInfiniteSet() {
        present = new boolean[1001];
        for (int i = 1; i <= 1000; i++) {
            present[i] = true;
        }
    }
    
    public int popSmallest() {
        for (int i = 1; i <= 1000; i++) {
            if (present[i]) {
                present[i] = false;
                return i;
            }
        }
        return -1;
    }
    
    public void addBack(int num) {
        present[num] = true;
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */