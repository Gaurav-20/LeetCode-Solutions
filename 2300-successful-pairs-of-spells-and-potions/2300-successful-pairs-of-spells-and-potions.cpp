class Solution {
public:
    int findNumberOfPotions(vector<int>& potions, int spell, long long success) {
        int low = 0, high = potions.size() - 1;
        if ((long long) potions[high] * (long long) spell < success) {
            return 0;
        }
        while (high > low) {
            int mid = (high + low) / 2;
            if ((long long) potions[mid] * (long long) spell >= success) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return potions.size() - low;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for (int& spell : spells) {
            res.push_back(findNumberOfPotions(potions, spell, success));
        }
        return res;
    }
};