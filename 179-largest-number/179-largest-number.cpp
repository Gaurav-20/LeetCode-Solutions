bool compare(const int& a, const int& b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    return ab > ba;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string res = "";
        for (int& n : nums) {
            res += to_string(n);
        }
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};