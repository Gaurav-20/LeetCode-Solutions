class Solution {
public:
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
	    for (auto& path : paths) {
		    stringstream ss(path);
		    string s, dir, file, content;
		    ss >> dir;
		    while (ss >> s) {
    			auto it = s.find('(');
    			file = s.substr(0, it);
    			content = s.substr(it);
    			mp[content].push_back(dir + "/" + file);
    		}
    	}

        vector<vector<string>> res;
        for (auto it : mp) {
            if (it.second.size() > 1) {
                res.push_back(it.second);
            }
        }
        return res;
    }
};