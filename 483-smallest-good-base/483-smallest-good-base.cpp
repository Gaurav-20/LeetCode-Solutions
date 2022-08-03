#define ll unsigned long long

class Solution {
public:
    string smallestGoodBase(string n) {
        ll num = stoll(n);
        for (ll p = log(num + 1) / log(2); p >= 2; p--) {
            ll low = 2, high = pow(num, 1.0 / (p - 1)) + 1;
            while (low <= high) {
                ll mid = low + (high - low) / 2, sum = 0;
                for (ll i = 0, f = 1; i < p; i++, f *= mid) {
                    sum += f;
                }
                if (sum < num) {
                    low = mid + 1;
                } else if (sum > num) { 
                    high = mid - 1;
                } else {
                    return to_string(mid);
                }
            }
        }
        return to_string(num - 1);
    }
};