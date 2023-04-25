class SmallestInfiniteSet {
public:
    vector<bool> hash;

    SmallestInfiniteSet() {
        hash.resize(1001);
        for (int it = 1; it <= 1000; it++) {
            hash[it] = 1;
        }
    }
    
    int popSmallest() {
        for (int it = 1; it <= 1000; it++) {
            if (hash[it] > 0) {
                hash[it] = 0;
                return it;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        hash[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */