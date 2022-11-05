class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() {
        isEnd = false;
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
        curr->isEnd = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        unordered_set<string> resultSet;
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[0].size(); y++) {
                findWords(board, x, y, root, "", resultSet);
            }
        }

        vector<string> result;
        for (auto it : resultSet) {
            result.push_back(it);
        }
        return result;
    }
private:
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, unordered_set<string>& result) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') {
            return;
        }
        
        if (root->children[board[x][y] - 'a']) {
            word = word + board[x][y];
            root = root->children[board[x][y] - 'a']; 
            if (root->isEnd) {
                result.insert(word);
                root->isEnd = false;
            }
            char c = board[x][y];
            board[x][y] = ' ';
            findWords(board, x + 1, y, root, word, result);
            findWords(board, x - 1, y, root, word, result);
            findWords(board, x, y + 1, root, word, result);
            findWords(board, x, y - 1, root, word, result);
            board[x][y] = c;
        }
    }
};