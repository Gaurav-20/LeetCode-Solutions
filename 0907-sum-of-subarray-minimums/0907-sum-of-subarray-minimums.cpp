#define MOD (int)1e9 + 7
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n, 0), right(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                left[i] += left[st.top()] + 1;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                right[i] += right[st.top()] + 1;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long long) (left[i] + 1) * (right[i] + 1) * arr[i];
            res %= MOD;
        }
        return (int)res;
    }
};