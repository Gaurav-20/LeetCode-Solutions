class Solution {
public:
    int cost(int pos, int moveCost, int pushCost, int mins, int secs) {
        if (min(mins, secs) < 0 || max(mins, secs) > 99) {
            return INT_MAX;
        }
        string digits = to_string(mins * 100 + secs); // convert fron MM:SS to MMSS
        int res = 0;
        for (char digit : digits) {
            res += pushCost + (pos == (digit - '0') ? 0 : moveCost);
            pos = digit - '0';
        }
        return res;
    }
    
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int mins = targetSeconds / 60, secs = targetSeconds % 60;
        // we have the following two choices i.e. mins : secs | mins - 1 : secs + 60
        // no other combination can be possible
        // any choice is possible only if mins >= 0 && secs <= 99 (secs always >= 0)
        return min(cost(startAt, moveCost, pushCost, mins, secs), 
                   cost(startAt, moveCost, pushCost, mins - 1, secs + 60)
        );
    }
};