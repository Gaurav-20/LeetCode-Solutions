class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int numStates = minutesToTest / minutesToDie + 1;
        return ceil((float) log(buckets) / (float) log(numStates)); // log buckets to base numStates
    }
};