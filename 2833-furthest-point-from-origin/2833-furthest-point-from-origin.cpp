class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0, countR = 0, count_ = 0;
        for (char c: moves) {
            countL += c == 'L';
            countR += c == 'R';
            count_ += c == '_';
        }
        return max(countL, countR) - min(countL, countR) + count_;
    }
};