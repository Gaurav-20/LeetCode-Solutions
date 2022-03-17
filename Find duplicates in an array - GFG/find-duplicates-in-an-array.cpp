// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        for (int i = 0; i < n; i++) {
            arr[arr[i] % n] += n;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 2 * n) {
                res.push_back(i);
            }
        }
        if (res.size() == 0) {
            res.push_back(-1);
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends