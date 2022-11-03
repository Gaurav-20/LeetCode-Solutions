class SnapshotArray {
public:
    int snapId = 0;
    map<int, map<int, int>> snapshots;
    
    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) {
            map<int, int> mp;
            mp[snapId] = 0;
            snapshots[i] = mp;
        }
    }
    
    void set(int index, int val) {
        snapshots[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = snapshots[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */