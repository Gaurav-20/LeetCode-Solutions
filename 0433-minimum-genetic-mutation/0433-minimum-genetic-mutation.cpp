vector<char> genes = { 'A', 'C', 'G', 'T' };

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> existsInBank;
        for (auto str : bank) {
            existsInBank[str] = true;
        }
        int mutations = 0;
        queue<pair<string, int>> q;
        q.push({ start, 0 });
        while (!q.empty()) {
            auto currentMutation = q.front();
            q.pop();
            if (currentMutation.first == end) {
                return currentMutation.second;
            }
            for (int i = 0; i < 8; i++) {
                for (auto gene : genes) {
                    string temp = currentMutation.first;
                    temp[i] = gene;
                    if (existsInBank[temp]) {
                        existsInBank[temp] = false;
                        q.push({temp, currentMutation.second + 1});
                    }
                }
            }
        }
        return -1;
    }
};