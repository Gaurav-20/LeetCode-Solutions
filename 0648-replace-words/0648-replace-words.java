public class TrieNode {
    public TrieNode[] children;
    public boolean isWord;
    
    TrieNode() {
        this.children = new TrieNode[26];
        this.isWord = false;
    }
}

class Trie {
    public TrieNode root;
    
    Trie() {
        this.root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode ptr = root;
        for (int i = 0; i < word.length(); i++) {
            int currIdx = word.charAt(i) - 'a';
            if (ptr.children[currIdx] == null) {
                ptr.children[currIdx] = new TrieNode();
            }
            ptr = ptr.children[currIdx];
        }
        ptr.isWord = true;
    }
    
    public String searchPrefix(String word) {
        TrieNode ptr = root;
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < word.length(); i++) {
            int currIdx = word.charAt(i) - 'a';
            if (ptr.children[currIdx] == null) {
                return word;
            }
            builder.append(word.charAt(i));
            ptr = ptr.children[currIdx];
            if (ptr.isWord) {
                break;
            }
        }
        return builder.toString();
    }
}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (String word : dictionary) {
            trie.insert(word);
        }
        List<String> result = new ArrayList<>();
        for (String word : sentence.split(" ")) {
            result.add(trie.searchPrefix(word));
        }
        return String.join(" ", result);
    }
}