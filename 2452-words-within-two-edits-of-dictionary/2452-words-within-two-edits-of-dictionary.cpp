class Solution {
public:
    int dist(string& a, string& b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            res += a[i] != b[i];
        }
        return res;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for (string query : queries) {
            bool flag = false;
            for (string dict : dictionary) {
                if (dist(query, dict) <= 2) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                res.push_back(query);
            }
        }
        return res;
    }
};