class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = *min_element(salary.begin(), salary.end());
        int maxSalary = *max_element(salary.begin(), salary.end());
        double res = 0.0;
        for (int& sal : salary) {
            res += sal;
        }
        res -= (maxSalary + minSalary);
        return res / (salary.size() - 2);
    }
};