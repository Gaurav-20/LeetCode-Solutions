// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getCount(int N) {
        // code here
        int ans = 0;
        for (int i = 2; i * (i - 1) / 2 < N; i++) {
            if ((N - i * (i - 1) / 2) % i == 0) {
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    }
    return 0;
}  // } Driver Code Ends