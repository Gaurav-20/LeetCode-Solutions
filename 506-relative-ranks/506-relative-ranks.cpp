class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int n = score.size();
        for (int i = 0; i < n; i++) {
            pq.push({ score[i], i });
        }
        int place = 1;
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            if (place == 1) {
                res[pq.top().second] = "Gold Medal";
            } else if (place == 2) {
                res[pq.top().second] = "Silver Medal";
            } else if (place == 3) {
                res[pq.top().second] = "Bronze Medal";
            } else {
                res[pq.top().second] = to_string(place);
            }
            place++;
            pq.pop();
        }
        return res;
    }
};