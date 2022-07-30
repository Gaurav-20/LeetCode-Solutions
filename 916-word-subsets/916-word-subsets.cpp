class Solution {
public:
    vector<int> getFreq(string& word){
	    vector<int> freq(26);
	    for (char& c : word) {
            freq[c - 'a']++;
        }
	    return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26);
        vector<string> res;
        for (string& word : words2) {
            vector<int> freq = getFreq(word);
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        for (string& word : words1) {
            vector<int> freq = getFreq(word);
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word);
            }
        }
        return res;
    }
};