class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n == 0) {
        	return true;
        }
        unordered_map<int, unordered_set<int>> mp;
        unordered_set<int> empty;
        for (int i = 0; i < n; i++) {
        	mp[stones[i]] = empty;
        }

        mp[0].insert(1);
        for (int i = 0; i < n - 1; i++) {
        	int currPos = stones[i];
        	for (int step: mp[currPos]) {
        		int nextPos = step + currPos; 
        		if (nextPos == stones.back()) {
        			return true;
        		}

        		if (mp.find(nextPos) != mp.end()) {
                    unordered_set<int> s = mp[nextPos]; 
                    s.insert(step + 1);
        		    s.insert(step);
        		    if (step - 1 > 0) {
                        s.insert(step - 1);
                    }
                    mp[nextPos] = s;
        		}
        	}
        }
        return false;
    }
};