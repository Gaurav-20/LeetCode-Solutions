class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int totalStamp = 0, turnStamp = -1, n = stamp.size();
        while (turnStamp) {
              turnStamp = 0;
              for (int sz = n; sz > 0; sz--) { 
                  for (auto i = 0; i <= n - sz; i++) {
                      string newStamp = 
                          string(i, '*') + stamp.substr(i, sz) + string(n - sz - i, '*');
                      auto pos = target.find(newStamp);
                      while (pos != string::npos) {
                          res.push_back(pos);
                          turnStamp += sz;
                          fill(target.begin() + pos, target.begin() + pos + n, '*');
                          pos = target.find(newStamp);
                      }
                  }
            }
            totalStamp += turnStamp;
        }
        reverse(res.begin(), res.end());
        return totalStamp == target.size() ? res : vector<int>();
    }
};