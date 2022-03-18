// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int N, int K) {
        // code here
        sort(A, A + N);
        int ans = INT_MAX;

        vector<int> pref(N + 1, 0);
       
        for (int i = 0; i < N ;i++) {
            pref[i + 1] = A[i] + pref[i];
        }
        
        for (int i = 0; i < N ;i++) {
           int idx = upper_bound(A, A + N, A[i] + K) - A;
           int su = pref[N] - pref[idx] - (N - idx) * (A[i] + K) + pref[i];
           ans = min(ans, su);
       }
       return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends