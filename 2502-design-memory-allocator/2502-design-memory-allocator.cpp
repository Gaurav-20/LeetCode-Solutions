class Allocator {
public:
    int n;
    vector<bool> memory;
    vector<int> res[1005];
    
    Allocator(int n) {
        this->n = n;
        memory.resize(n);
        for (int i = 0; i < 1005; i++) {
            res[i].clear();
        }
    }
    
    int allocate(int size, int mID) {
        int free = 0;
        for (int i = 0; i < n; i++) {
            if (memory[i]) {
                free = 0;
            } else {
                free++;
                if (free == size) {
                    int low = i - size + 1;
                    for (int i = 0; i < size; i++) {
                        memory[i + low] = true;
                        res[mID].push_back(i + low);
                    }
                    return low;
                }
            }
        }
        return -1;
    }
    
    int free(int mID) {
        vector<int> v = res[mID];
        for (int i : v) {
            memory[i] = false;
        }
        res[mID].clear();
        return v.size();
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */