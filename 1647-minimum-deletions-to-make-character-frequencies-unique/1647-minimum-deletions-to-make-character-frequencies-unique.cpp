class Solution {
public:
    int minDeletions(string s) {
        vector<int> freqs(26);
        for (char ch: s) {
		    freqs[ch - 'a']++;
        }
	    sort(freqs.begin(), freqs.end());
    	int res = 0;
	    for (int i = freqs.size() - 2; i >= 0; i--) {
		    if (freqs[i] >= freqs[i + 1]) {
			    if (freqs[i + 1] == 0) {
				    res += freqs[i];
                } else {
				    res += freqs[i] - freqs[i + 1] + 1;
                }
			    freqs[i] = max(freqs[i + 1] - 1, 0);
            }
        }
        return res;
    }
};