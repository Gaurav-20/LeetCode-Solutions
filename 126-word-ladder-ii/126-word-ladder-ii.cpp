class Solution {
public:
    bool isNeighbour(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                cnt++ ;
            }
        }
        return cnt == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);
        int n = wordList.size();
        for (int i = 1; i < n; i++) {
            if (wordList[i] == wordList[0]) {
                wordList[i] = wordList.back();
                wordList.pop_back();
                break;
            }
        }
        n = wordList.size();
        unordered_map<string, int> wordToIndex;
        for(int i = 0; i < n; i++) {
            wordToIndex.insert({ wordList[i], i });
        }
        if (!wordToIndex.count(endWord)) {
            return {};
        }
        vector<vector<int>> edges(wordToIndex.size());
        for (int i = 0 ; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isNeighbour(wordList[i], wordList[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        int startNode = 0, targetNode = wordToIndex[endWord], r = 0, minSteps = INT_MAX;
        queue<int> q;
        vector<int> dis(n, INT_MAX);
        dis[startNode] = 0;
        q.push(startNode);
        while (!q.empty()) {
            int sz  = q.size() ;
            for (int i = 0; i < sz; i++) {
                int fr = q.front();
                q.pop();
                if (fr == targetNode) {
                    minSteps = min(minSteps, r);
                }
                for (auto it : edges[fr]) {
                    if (r + 1 < dis[it]) {
                        dis[it] = r + 1;
                        q.push(it);
                    }
                }
            }
            r++;
        }
        if (minSteps == INT_MAX) {
            return {};
        }
        queue<vector<string>> q2;
        q2.push({ wordList[targetNode] }) ;
        r = minSteps;
        while (r) {
             int sz = q2.size();
             for (int i = 0; i < sz; i++) {
                vector<string> seq = q2.front();
                q2.pop();
                string back = seq.back();
                int curr = wordToIndex[back];
                for (auto it : edges[curr]) {
                    if (dis[it] == r - 1) {
                        seq.push_back(wordList[it]) ;
                        q2.push(seq);
                        seq.pop_back();
                    }
                }
            }
            r-- ;
        }
        vector<vector<string>> res;
        while (!q2.empty()) {
            vector<string> temp = q2.front();
            q2.pop();
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};