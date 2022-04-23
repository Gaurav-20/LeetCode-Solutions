string TINYURL = "https://tinyurl.com/";
int length = TINYURL.size();

string toString(long long num) {
    string res = "";
    while (num > 0) {
        res += (num % 10) + '0';
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

class Solution {
public:
    unordered_map<string, string> code;
    hash<string> hasher;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string hash = toString(hasher(longUrl));
        code[hash] = longUrl;
        return TINYURL + hash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code[shortUrl.substr(length)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));