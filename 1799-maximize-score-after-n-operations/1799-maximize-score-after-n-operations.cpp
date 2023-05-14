class Solution {
public:
    bool isBitSet(int& num, int bitIdx) {
        return (num & (1 << bitIdx)) != 0;
    }

    void setBit(int& num, int bitIdx) {
        num = num | (1 << bitIdx);
    }
    
    int solve(vector<int>& nums,  map<int, int>& mp, int visited, int multiplier) {
        if (mp.count(visited)) {
            return mp[visited];
        }   
        int maxScore = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (isBitSet(visited, i)) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (isBitSet(visited, j)) {
                    continue;
                }
                int newVisited = visited;
                setBit(newVisited, i);
                setBit(newVisited, j);
                
                int currScore = multiplier * __gcd(nums[i], nums[j]);
                int nextMaxScore = solve(nums, mp, newVisited, multiplier + 1);
                int totalScore = currScore + nextMaxScore;
                maxScore = max(maxScore, totalScore);
                // rather than unSetting we will use the same old mask in next Iteration
            }
        }
        return mp[visited] = maxScore;
    }
    
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int visited = 0;
        map<int, int>mp;
        return solve(nums, mp, visited, 1);
    }
};