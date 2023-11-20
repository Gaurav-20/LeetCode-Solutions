class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        travel.insert(travel.begin(), 0);
        int n = travel.size();
	    for (int i = 1; i < n; i++) {
		    travel[i] += travel[i - 1];
	    }
        int countM = 0, countG = 0, countP = 0;
        int lastM = -1, lastG = -1, lastP = -1;
        for (int i = 0; i < n; i++) {
            string curr = garbage[i];
            for (char c : curr) {
                if (c == 'M') {
                    countM++;
                    lastM = i;
                } else if (c == 'G') {
                    countG++;
                    lastG = i;
                } else {
                    countP++;
                    lastP = i;
                }
            }
        }
        int res = 0;
        if (lastM != -1) {
            res = max(res, res + countM + (travel[lastM]));
        }
        if (lastG != -1) {
            res = max(res, res + countG + (travel[lastG]));
        }
        if (lastP != -1) {
            res = max(res, res + countP + (travel[lastP]));
        }
        return res;
    }
};