/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    vector<string> reduceWordList (int match, string word, vector<string>& wordlist){
        vector<string> filterList; 
        for (string s : wordlist) {
            int count = 0;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == s[i]) {
                    count++;
                }
            }
            if (count == match) {
                filterList.push_back(s);
            }
        }
        return filterList;
    }
    
    string getCommonWord (vector<string>& wordlist) {
        string bestWord; 
        map<int, map<char, int>> freq;
        int bestScore = 0;
        for (string s : wordlist) {
            for (int i = 0; i < s.size(); i++) {
                freq[i][s[i]]++;
            }
        }
        
        for (string s: wordlist) {
            int currentScore = 0;
            for (int i = 0; i < s.size(); i++) {
                currentScore += freq[i][s[i]];
            }
            if (currentScore > bestScore) {
                bestScore = currentScore;
                bestWord = s;
            }
        }
        return bestWord;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        while (!wordlist.empty()) {
            string guessWord = getCommonWord(wordlist);
            int match = master.guess(guessWord);
            if (match == 6) {
                return;
            }
            wordlist = reduceWordList(match, guessWord, wordlist);
        }
    }
};