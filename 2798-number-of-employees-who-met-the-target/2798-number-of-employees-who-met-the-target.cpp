class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int numEmployees = 0;
        for (int hour: hours) {
            numEmployees += hour >= target;
        }
        return numEmployees;
    }
};