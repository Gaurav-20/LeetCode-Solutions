class SummaryRanges {
public:
    map<int, vector<int>> m;
    
    SummaryRanges() { }
    
    void addNum(int val) {
        if (m.count(val)) {
            return;
        }
        auto high = m.lower_bound(val);
        auto low = (high == m.begin()) ? m.end() : prev(high);

        if (low != m.end() && high != m.end() && low->second[1] + 1 == val && high->first == val + 1) {
            low->second[1] = high->second[1];
            m.erase(high);
        } else if (low != m.end() && low->second[1] + 1 >= val) {
            low->second[1] = max(low->second[1], val);
        } else if (high != m.end() && high->first == val + 1) {
            m[val] = {val, high->second[1]};
            m.erase(high);
        } else {
            m[val] = {val, val};
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */