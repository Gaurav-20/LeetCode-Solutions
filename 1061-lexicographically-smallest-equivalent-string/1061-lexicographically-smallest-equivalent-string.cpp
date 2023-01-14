class Solution {
public:
    vector<int> dsu;
    
    int getParent(char child) {
        int node = child - 'a';
        while(dsu[node] != node) {
            node = dsu[node];
        }
        return node;
    }
    
    void unite(char node1, char node2) {
        int parentNode1 = getParent(node1);
        int parentNode2 = getParent(node2);
        if (parentNode1 <= parentNode2) {
            dsu[parentNode2] = parentNode1;
        } else {
            dsu[parentNode1] = parentNode2;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        dsu = vector<int>(26);
        for (int i = 0; i < 26; i++) {
            dsu[i] = i;
        }
        for (int i = 0; i < s1.size(); i++) {
            unite(s1[i], s2[i]);
        }
        string res;
        for (char& ch : baseStr) {
            res.push_back(getParent(ch) + 'a');
        }
        return res;
    }
};