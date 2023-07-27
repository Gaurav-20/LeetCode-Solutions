class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        int i = batteries.size() - 1;
        while (i >= 0 && sum / n < batteries[i]) {
            sum -= batteries[i];
            n--;
            i--;
        }
        return sum / n;
    }
};