class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c: s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto &[ch, frq]: freq) {
            maxHeap.push({ frq, ch });
        }

        string res;
        while (maxHeap.size() >= 2) {
            auto [freq1, char1] = maxHeap.top();
            maxHeap.pop();
            auto [freq2, char2] = maxHeap.top();
            maxHeap.pop();

            res += char1;
            res += char2;

            if (--freq1 > 0) {
                maxHeap.push({ freq1, char1 });
            }
            if (--freq2 > 0) {
                maxHeap.push({ freq2, char2 });
            }
        }

        if (!maxHeap.empty()) {
            auto [freq, ch] = maxHeap.top();
            if (freq > 1) {
                return "";
            }
            res += ch;
        }
        return res;
    }
};