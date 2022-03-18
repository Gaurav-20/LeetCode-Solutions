// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution {
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s) {
       //Your code here
       unordered_map<char, int> mp;
       for (char& c : s) {
           mp[c]++;
       }
       char res = '$';
       for (char& c : s) {
           if (mp[c] == 1) {
               res = c;
               break;
           }
       }
       return res;
    }

};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
  // } Driver Code Ends