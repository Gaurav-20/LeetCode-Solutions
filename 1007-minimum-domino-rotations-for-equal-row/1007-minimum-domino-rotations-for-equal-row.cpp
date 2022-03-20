class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int len = tops.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < len; i++) {
            freq[tops[i]]++;
            freq[bottoms[i]]++;
        }
        bool possible = false;
        int candidate = -1;
        for (auto it : freq) {
            if (it.second >= len) {
                candidate = it.first;
                possible = true;
            }
        }
        if (!possible) {
            return -1;
        }
        int topSwap = 0, bottomSwap = 0;
        for (int i = 0; i < len; i++) {
            if (tops[i] == candidate || bottoms[i] == candidate) {
                if (tops[i] == candidate && bottoms[i] == candidate) {
                    continue;
                } else if (tops[i] == candidate) {
                    bottomSwap++;
                } else {
                    topSwap++;
                }
            } else {
                possible = false;
                break;
            }
        }
        if (!possible) {
            return -1;
        }
        return min(topSwap, bottomSwap);
    }
};