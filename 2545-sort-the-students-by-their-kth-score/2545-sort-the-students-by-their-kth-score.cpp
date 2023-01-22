int kk;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[kk] > b[kk];
}

class Solution {
public:
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        kk = k;
        sort(score.begin(), score.end(), compare);
        return score;
    }
};