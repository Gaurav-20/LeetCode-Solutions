class FreqStack {
public:
    vector<vector<int>> st;
    unordered_map<int, int> freq;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        if (freq[val] > st.size()) {
            vector<int> v = {val};
            st.push_back(v);
        } else {
            st[freq[val] - 1].push_back(val);
        }
    }
    
    int pop() {
        vector<int> res = st.back();
        st.pop_back();
        if (res.size() == 1) {
            freq[res[0]]--;
            return res[0];
        } else {
            freq[res.back()]--;
            int b = res.back();
            res.pop_back();
            st.push_back(res);
            return b;
        }
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */