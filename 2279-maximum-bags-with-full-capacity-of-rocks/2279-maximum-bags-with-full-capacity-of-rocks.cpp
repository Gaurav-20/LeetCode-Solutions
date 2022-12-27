class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int len = capacity.size();
        vector<int> diff;
        for (int i = 0; i < len; i++) {
            if (capacity[i] >= rocks[i]) {
                diff.push_back(capacity[i] - rocks[i]);
            }
        }
        sort(diff.begin(), diff.end());
        len = diff.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (diff[i] == 0) {
                res++;
            } else if (diff[i] <= additionalRocks) {
                res++;
                additionalRocks -= diff[i];
            } else {
                break;
            }
        }
        return res;
    }
};