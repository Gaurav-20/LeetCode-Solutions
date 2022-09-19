struct Node {
    string dir = "";
    vector<string> files;
};

class Solution {
public:
    Node split(string str) {
        string temp = "";
        int n = str.size();
        Node res;
        for (int i = 0; i < n; i++) {
            if (str[i] != ' ') {
                temp += str[i];
            } else {
                if (res.dir == "") {
                    res.dir = temp;
                } else {
                    res.files.push_back(temp);
                }
                temp = "";
            }
        }
        if (temp != "") {
            res.files.push_back(temp);
        }
        return res;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for (string path : paths) {
            Node node = split(path);
            string dir = node.dir;
            vector<string> files = node.files;
            for (auto file : files) {
                int i;
                for (i = 0; i < file.size(); i++) {
                    if (file[i] == '(') {
                        break;
                    }
                }
                string fileName = file.substr(0, i);
                string content = file.substr(i);
                mp[content].push_back(dir + "/" + fileName);
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