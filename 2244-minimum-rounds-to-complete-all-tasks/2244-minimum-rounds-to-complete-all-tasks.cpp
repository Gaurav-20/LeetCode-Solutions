class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> taskCount;
        for (int& task : tasks) {
            taskCount[task]++;
        }
        int res = 0;
        for (auto& it : taskCount) {
            if (it.second == 1) {
                return -1;
            } else {
                res += ceil((float) it.second / 3.0);
            }
        }
        return res;
    }
};