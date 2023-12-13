class SmallestInfiniteSet {

    int currentSmallestElement = 1;
    Set<Integer> set;
    
    public SmallestInfiniteSet() {
        currentSmallestElement = 1;
        set = new HashSet<>();
    }
    
    public int popSmallest() {
        if (!set.isEmpty()) {
            int res = Collections.min(set);
            set.remove(res);
            return res;
        }
        return currentSmallestElement++;
    }
    
    public void addBack(int num) {
        if (currentSmallestElement > num) {
            set.add(num);
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */