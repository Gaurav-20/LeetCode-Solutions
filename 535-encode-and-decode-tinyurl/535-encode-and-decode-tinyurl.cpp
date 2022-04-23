string TINYURL = "https://tinyurl.com/";
int length = TINYURL.size();

class Solution {
public:
    int it = 0;
    unordered_map<int, string> code;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        code[++it] = longUrl;
        return TINYURL + to_string(it);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code[stoi(shortUrl.substr(length))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));