class TrieNode {
    
    public TrieNode[] children;
    public boolean isEndOfWord;
    
    TrieNode() {
        this.children = new TrieNode[26];
        this.isEndOfWord = false;
    }
}

class Trie {

    public TrieNode root;
    
    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode ptr = root;
        for (int i = 0; i < word.length(); i++) {
            int charIdx = word.charAt(i) - 'a';
            if (ptr.children[charIdx] == null) {
                ptr.children[charIdx] = new TrieNode();
            }
            ptr = ptr.children[charIdx];
        }
        ptr.isEndOfWord = true;
    }
    
    public boolean search(String word) {
        TrieNode ptr = root;
        for (int i = 0; i < word.length(); i++) {
            int charIdx = word.charAt(i) - 'a';
            if (ptr.children[charIdx] == null) {
                return false;
            }
            ptr = ptr.children[charIdx];
        }
        return ptr.isEndOfWord == true;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode ptr = root;
        for (int i = 0; i < prefix.length(); i++) {
            int charIdx = prefix.charAt(i) - 'a';
            if (ptr.children[charIdx] == null) {
                return false;
            }
            ptr = ptr.children[charIdx];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */