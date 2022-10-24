class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<vector<int>> AA(2), BB(2);
        for (int a : nums) {
            AA[a % 2].push_back(a);
        }
        
        for (int b: target) {
            BB[b % 2].push_back(b);
        }
        
        sort(AA[0].begin(), AA[0].end());
        sort(AA[1].begin(), AA[1].end());
        sort(BB[0].begin(), BB[0].end());
        sort(BB[1].begin(), BB[1].end());
        
        long long res = 0;
        
        for (int i = 0; i < AA[0].size(); i++) {
            res += abs(AA[0][i] - BB[0][i]) / 2;
        }
        
        for (int i = 0; i < AA[1].size(); i++) {
            res += abs(AA[1][i] - BB[1][i]) / 2;
        }
        
        return res / 2;
    }
};