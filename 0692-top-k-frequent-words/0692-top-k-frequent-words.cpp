#define psi pair<string, int>

class Compare {
public:
    bool operator()(const psi& a, const psi& b) {
        return (a.second > b.second) || (a.second == b.second && a.first < b.first);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> count;
        for (string& word : words) {
            count[word]++;
        }
        priority_queue<psi, vector<psi>, Compare> pq;
        for (auto it : count) {
            pq.push(it);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};