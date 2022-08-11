class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<int, int> mp;
        for (char& c : moves) {
            mp[c]++;
        }
        return (mp['L'] == mp['R']) && (mp['U'] == mp['D']);
    }
};