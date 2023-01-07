class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Let's consider the start point from the end and vice versa
        // This helps in case when the fuel is not enough
        int start = gas.size() - 1;
        int end = 0;
        
        // sum holds the amount of fuel we currently have left
        int sum = gas[start] - cost[start];
        
        // whenever start == end, we know that the journey is complete
        // we just need to check the fuel it should not be negative
        while (start > end) {
            // if sum >= 0, we can carry on the journey, 
            // increment the end ptr which is at left in this case
            // if sum < 0, we cannot go further, so decrement start
            // and now carry on with this newer value of sum
            if (sum >= 0) {
                sum += gas[end] - cost[end];
                end++;
            } else {
                start--;
                sum += gas[start] - cost[start];
            }
        }
        return (sum >= 0) ? start : -1;
    }
};