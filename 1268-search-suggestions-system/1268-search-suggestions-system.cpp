struct TrieNode {
    vector<TrieNode*> child{ vector<TrieNode*>(26, nullptr) };
    string* word{ };
};

void insert(TrieNode* root, string& word) {
    for (char c : word) {
        c -= 'a';
        if (root->child[c] == nullptr) {
            root->child[c] = new TrieNode();
        }
        root = root->child[c];
    }
    root->word = &word;
}

void dfs(TrieNode* root, int limit, vector<string>& result) {
    if (root == nullptr) {
        return;
    }
    if (result.size() == limit) {
        return;
    }
    if (root->word != nullptr) {
        result.push_back(*root->word);
    }
    for (int i = 0; i < 26; i++) {
        dfs(root->child[i], limit, result);
    }
}

vector<string> getWords(TrieNode* root, int limit) {
    vector<string> result;
    dfs(root, limit, result);
    return result;
}

class Solution {
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for (string& product : products) {
            insert(root, product);
        }

        vector<vector<string>> ans;
        TrieNode* curr = root;
        for (char c : searchWord) {
            c -= 'a';
            if (curr && curr->child[c]) {
                curr = curr->child[c];
                ans.push_back(getWords(curr, 3));
            } else {
                curr = nullptr;
                ans.emplace_back();
            }
        }
        return ans;
    }
};