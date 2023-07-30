class Solution {
public:
    string concatenate(string a, string b) {
        if (a.find(b) != string::npos) {
            return a;
        }
        for (int i = min(a.size(), b.size()); i >= 0; i--) {
            if (a.substr(a.size() - i) == b.substr(0, i)) {
                return a + b.substr(i);
            }
        }
        return a + b;
    }
    
    string generate(string a, string b, string c) {
        string result = a;
        result = concatenate(result, b);
        result = concatenate(result, c);
        return result;
    }
    
    string minimumString(string a, string b, string c) {
        vector<string> strs = {
            generate(a, b, c),
            generate(a, c, b),
            generate(b, a, c),
            generate(b, c, a),
            generate(c, a, b),
            generate(c, b, a)
        };
        return *min_element(strs.begin(), strs.end(), [](const auto &a, const auto &b) {
            return a.size() == b.size() ? a < b : a.size() < b.size();
        });
    }
};