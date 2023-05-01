class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = *min_element(salary.begin(), salary.end());
        int maxSalary = *max_element(salary.begin(), salary.end());
        double sum = 0.0;
        for (int& sal: salary) {
            if (sal != maxSalary && sal != minSalary) {
                sum += sal;
            }
        }
        return sum / (salary.size() - 2);
    }
};