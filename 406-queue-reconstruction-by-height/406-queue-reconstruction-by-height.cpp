bool comp(const vector<int>& a, const vector<int>& b) { 
    return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
}

class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        for (auto& p : people) { 
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};