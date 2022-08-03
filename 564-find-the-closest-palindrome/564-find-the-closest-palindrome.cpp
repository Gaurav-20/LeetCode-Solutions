#define ll long long

class Solution {
public:
    ll getPalindrome(ll left, bool isOddLength) {
        ll res = left;
        if (isOddLength) {
            left /= 10;
        }
        while (left > 0) {
            res = res * 10 + left % 10;
            left /= 10;
        }
        return res;
    }
    
    string nearestPalindromic(string n) {
        ll len = n.size();
        ll mid = (len % 2 == 0) ? len / 2 - 1 : len / 2;
        ll left = stoll(n.substr(0, mid + 1));
        
        vector<ll> candidates;
        candidates.push_back(getPalindrome(left, len % 2)); // 12321
        candidates.push_back(getPalindrome(left + 1, len % 2)); // 12421
        candidates.push_back(getPalindrome(left - 1, len % 2)); // 12221
        candidates.push_back((ll) pow(10, len - 1) - 1); // 9999
        candidates.push_back((ll) pow(10, len) + 1); // 100001
        
        ll diff = LLONG_MAX, res = 0, num = stoll(n);
        for (ll candidate : candidates) {
            if (candidate == num) {
                continue;
            }
            if (abs(candidate - num) < diff) {
                diff = abs(candidate - num);
                res = candidate;
            } else if (abs(candidate - num) == diff) {
                res = min(res, candidate);
            }
        }
        return to_string(res);
    }
};