#define MAX_CHAR 26

class Trie {
public:
    bool isEndOfWord;
    Trie* children[MAX_CHAR];
    
    Trie() {
        isEndOfWord = false;
        for (int i = 0; i < MAX_CHAR; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* ptr = root;
        for (auto& w : word) {
            int index = w - 'a';
            if (ptr->children[index] == nullptr) {
                ptr->children[index] = new Trie();
            }
            ptr = ptr->children[index];
        }
        ptr->isEndOfWord = true;
    }
    
    bool dfs(string word, Trie* ptr) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] != '.') {
                int index = word[i] - 'a';
                if (ptr->children[index] == nullptr) {
                    return false;
                }
                ptr = ptr->children[index];
            } else {
                int j = 0;
                bool found = false;
                for (j = 0; j < MAX_CHAR; j++) {
                    if (ptr->children[j]) {
                        found |= dfs(word.substr(i + 1), ptr->children[j]);
                    }
                    if (found) {
                        return true;
                    }
                }
                if (j == MAX_CHAR) {
                    return false;
                }
            }
        }
        return ptr->isEndOfWord;
    }
    
    bool search(string word) {
        Trie* ptr = root;
        return dfs(word, ptr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */