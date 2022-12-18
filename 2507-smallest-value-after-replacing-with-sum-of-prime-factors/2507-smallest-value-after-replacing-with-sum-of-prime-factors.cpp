class Solution {
public:
    
    int findPrimeFactorSum(int num) {
        int res = 0, n = num;
        for (int i = 2; i * i <= num; i++) {
            while (n % i == 0) {
                res += i;
                n /= i;
            }
        }
        if (n > 1) {
            res += n;
        }
        return res;
    }
    
    int smallestValue(int n) {
        int res = n;
        unordered_set<int> st;
        st.insert(n);
        while (true) {
            n = findPrimeFactorSum(n);
            res = min(res, n);
            if (st.find(n) == st.end()) {
                st.insert(n);
            } else {
                break;
            }
        }
        return res;
    }
};