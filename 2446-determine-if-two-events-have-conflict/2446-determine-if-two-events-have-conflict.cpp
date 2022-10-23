class Solution {
public:
    vector<int> helper(vector<string>& events) {
        vector<int> res;
        for (string event : events) {
            int timer = ((event[0] - '0') * 10 + (event[1] - '0')) * 60 + ((event[3] - '0') * 10 + (event[4] - '0'));
            res.push_back(timer);
        }
        return res;
    }
    
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<int> v1 = helper(event1);
        vector<int> v2 = helper(event2);
        return !(v1[1] < v2[0] || v2[1] < v1[0]);
    }
};