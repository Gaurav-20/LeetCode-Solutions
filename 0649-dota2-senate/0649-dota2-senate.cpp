class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            (senate[i] == 'R')? q1.push(i): q2.push(i);
        }
        while (!q1.empty() && !q2.empty()) {
            int rIndex = q1.front(), dIndex = q2.front();
            q1.pop();
            q2.pop();
            (rIndex < dIndex)? q1.push(rIndex + n): q2.push(dIndex + n);
        }
        return (q1.size() > q2.size())? "Radiant": "Dire";
    }
};