class Solution {
public:
    unordered_map<string, int> skillToIdx;

    vector<int> smallestSufficientTeam(vector<string>& reqSkills, vector<vector<string>>& people) {
        int target = pow(2, (int) reqSkills.size()) - 1;
        for (int i = 0; i < reqSkills.size(); i++) {
            skillToIdx[reqSkills[i]] = i;
        }
        return bfs(target, people);
    }

    int computeMask(vector<string>& skills) {
        int mask = 0;
        for (string skill : skills) {
            mask |= (1 << skillToIdx[skill]);
        }
        return mask;
    }

    vector<int> bfs(int target, vector<vector<string>>& people) {
        queue<pair<int, vector<int>>> q;
        vector<int> start;
        q.push({ 0, start });
        unordered_set<int> seen;
        seen.insert(0);
        while (!q.empty()) {
            auto currPair = q.front();
            q.pop();
            int currMask = currPair.first;
            vector<int> currTeam = currPair.second;
            if (currMask == target) {
                return currTeam;
            }
            for (int i = 0; i < people.size(); i++) {
                vector<int> nextTeam = vector<int>(currTeam.begin(), currTeam.end());
                nextTeam.push_back(i);
                int nextMask = currMask | computeMask(people[i]);
                if (seen.count(nextMask) == 0) {
                    seen.insert(nextMask);
                    q.push({ nextMask, nextTeam });
                }
            }
        }
        return {};
    }
};