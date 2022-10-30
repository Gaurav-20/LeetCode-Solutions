class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = views.size();
        map<string, string> creatorToIds;
        map<string, long long> creatorToViews;
        map<string, long long> creatorToMostViewed;
        for (int i = 0; i < n; i++) {
            if (creatorToMostViewed[creators[i]] < views[i]) {
                creatorToMostViewed[creators[i]] = views[i];
                creatorToIds[creators[i]] = ids[i];
            } else if (creatorToMostViewed[creators[i]] == views[i]) {
                if (creatorToIds.find(creators[i]) != creatorToIds.end()) {
                    creatorToIds[creators[i]] = min(creatorToIds[creators[i]], ids[i]);
                } else {
                    creatorToIds[creators[i]] = ids[i];
                }
            }
            creatorToViews[creators[i]] += views[i];
        }
        long long maxViews = -1;
        for (auto it : creatorToViews) {
            maxViews = max(maxViews, it.second);
        }
        vector<vector<string>> res;
        for (auto it : creatorToViews) {
            if (it.second == maxViews) {
                res.push_back({ it.first, creatorToIds[it.first] });
            }
        }
        return res;
    }
};