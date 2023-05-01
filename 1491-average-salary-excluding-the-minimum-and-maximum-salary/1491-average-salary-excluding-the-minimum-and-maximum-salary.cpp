class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double sum = (double) accumulate(salary.begin() + 1, salary.end() - 1, 0);
        return sum / (salary.size() - 2);
    }
};