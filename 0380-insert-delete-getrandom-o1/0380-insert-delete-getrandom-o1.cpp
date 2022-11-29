class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> hash;

    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (hash.find(val) != hash.end()) {
            return false;
        }
        arr.push_back(val);
        hash[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (hash.find(val) != hash.end()) {
            int pos = hash[val];
            if (pos == arr.size() - 1) {
                arr.pop_back();
                hash.erase(val);
                return true;
            }
            swap(arr[pos], arr[arr.size() - 1]);
            hash[arr[pos]] = pos;
            arr.pop_back();
            hash.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        if (arr.size() > 0) {
            return arr[rand() % arr.size()];
        }
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */