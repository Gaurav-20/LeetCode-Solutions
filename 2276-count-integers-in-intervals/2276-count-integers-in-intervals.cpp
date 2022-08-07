class CountIntervals {
private:
    int counts;
    set<pair<int, int>> pool;
public:

    CountIntervals() {
        counts = 0;
    }
    
    void add(int left, int right) {
        auto it = pool.lower_bound({ left, right });
        if (it != pool.end()) {
            auto [qleft, qright] = *it;
            if (qleft <= right) {
                counts -= qright - qleft + 1;
                pool.erase(it);
                add(left, max(right, qright));
                return;
            }
        }
        if (it != pool.begin()) {
            auto [pleft, pright] = *(--it);
            if (pright >= left) {
                counts -= pright - pleft + 1;
                pool.erase(it);
                add(pleft, max(pright, right));
                return;
            }
        }
        counts += right - left + 1;
        pool.insert({ left, right });
    }
    
    int count() {
        return counts;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */