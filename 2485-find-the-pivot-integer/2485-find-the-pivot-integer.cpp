class Solution {
public:
    int sum(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; i++) {
            res += i;
        }
        return res;
    }
    
    int pivotInteger(int n) {
        for (int x = 1; x <= n; x++) {
            if (sum(1, x) == sum(x, n)) {
                return x;
            }
        }
        return -1;
    }
};