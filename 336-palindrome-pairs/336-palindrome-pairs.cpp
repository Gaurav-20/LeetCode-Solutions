struct TrieNode {
    TrieNode* next[26];
    int index = -1;
    vector<int> list;
};

class Solution {
public:
    bool isPalindrome(string& word, int i, int j) {
        while (i < j) {
    	    if (word[i++] != word[j--]) {
                return false;
            }
        }
        return true;
    }

    void addWord(TrieNode* root, string word, int index) {
        for (int i = word.size() - 1; i >= 0; i--) {
            int j = word[i] - 'a';	
            if (root->next[j] == nullptr) {
                root->next[j] = new TrieNode();
            }				
            if (isPalindrome(word, 0, i)) {
                root->list.push_back(index);
            }			
            root = root->next[j];
        }
        root->list.push_back(index);
        root->index = index;
    }
    
    void search(TrieNode* root, vector<string>& words, int i, vector<vector<int>>& res) {
        for (int j = 0; j < words[i].size(); j++) {	
    	    if (root->index >= 0 && root->index != i 
                && isPalindrome(words[i], j, words[i].size() - 1)) {
    	    res.push_back({ i, root->index });
    	    }
    	    root = root->next[words[i][j] - 'a'];
      	    if (root == nullptr) {
                return;
            }
        }
        for (int j : root->list) {
    	    if (i == j) {
                continue;
            }
    	    res.push_back({ i, j });
        }
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        TrieNode* root = new TrieNode();
        int len = words.size();
        for (int idx = 0; idx < len; idx++) {
            addWord(root, words[idx], idx);
        }
        for (int idx = 0; idx < len; idx++) {
            search(root, words, idx, res);
        }
        return res;
    }
};