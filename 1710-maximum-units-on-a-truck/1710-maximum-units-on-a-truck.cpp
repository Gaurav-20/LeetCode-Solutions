class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return (a[1] > b[1]);
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int maxUnits = 0;
        for (vector<int>& box : boxTypes) {
            if (truckSize == 0) {
                break;
            }
            int currBoxes = min(box[0], truckSize);
            truckSize -= currBoxes;
            maxUnits += currBoxes * box[1];
        }
        return maxUnits;
    }
};