class Solution {
public:
    vector<int> findFactors(int n) {
        vector<int> res;
        if (n % 2 == 0) {
            res.push_back(2);
        }
        while (n % 2 == 0) {
            n /= 2;
        }
        for (int i = 3; i * i <= n; i = i + 2) {
            if (n % i == 0) {
                res.push_back(i);
            }
            while (n % i == 0) {
                n /= i;
            }
        } 
        if (n > 2) {
            res.push_back(n);
        }
        return res;
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> factors = findFactors(nums[i]);
            for (int f : factors) {
                st.insert(f);
            }
        }
        return st.size();
    }
};