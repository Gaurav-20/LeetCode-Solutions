vector<string> morse = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> st;
        for (string word : words) {
            string curr;
            for (char w : word) {
                curr += morse[w - 'a'];
            }
            st.insert(curr);
        }
        return st.size();
    }
};