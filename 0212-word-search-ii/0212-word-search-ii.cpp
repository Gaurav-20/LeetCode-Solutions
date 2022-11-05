class TrieNode {
public:
    string word;
    vector<TrieNode*> children;
    TrieNode() {
        word = "";
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie {
private:
    TrieNode* root;

public:
    TrieNode* getRoot() {
        return root;
    }

    Trie(vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            addWord(word);
        }
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
               curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->word = word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        vector<string> result;
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[0].size(); y++) {
                findWords(board, x, y, root, result);
            }
        }
        return result;
    }

private:
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, vector<string>& result) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '#' ||
           !root->children[board[x][y] - 'a']) {
            return;
        }
        root = root->children[board[x][y] - 'a']; 
        if (root->word != "") {
            result.push_back(root->word);
            root->word = "";
        }
        char c = board[x][y];
        board[x][y] = '#';
        findWords(board, x + 1, y, root, result);
        findWords(board, x - 1, y, root, result);
        findWords(board, x, y + 1, root, result);
        findWords(board, x, y - 1, root, result);
        board[x][y] = c;
    }
};