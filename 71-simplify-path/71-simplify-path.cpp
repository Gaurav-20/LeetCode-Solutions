class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        stack<string> s;
        int n = path.size();
        int p1{0}, p2{0};
        while (p1 < n && p2 < n) {
            while (p1 < n && path[p1] == '/') {
                p1++;
            }
            p2 = p1;
            while (p2 < n && path[p2] != '/') {
                p2++;
            }
            if (path[p1] == '.' && p2 == p1 + 2 && path[p1 + 1] == '.' && !s.empty()) {
                s.pop();
            }
            if (path[p1] != '.' || p2 >= p1 + 3) {
                s.push(path.substr(p1, p2 - p1));
            }
            p1 = p2 + 1;
        }
        while (!s.empty()) {
            string top = s.top();
            s.pop();
            if (result.size() > 0) {
                result = top + "/" + result;
            } else {
                result = top;
            }
        }
        return "/" + result;
    }
};