class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (auto candy : candies) {
            res.push_back((candy + extraCandies) >= maxCandies);
        }
        return res;
    }
};