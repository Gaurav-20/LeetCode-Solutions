// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {
        // Your code here
        bool allNeg = true;
        int maxNeg = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxNeg = max(maxNeg, arr[i]);
            if (arr[i] > 0) {
                allNeg = false;
            }
        }
        if (allNeg) {
            return maxNeg;
        }
        int localMax = 0, globalMax = 0;
        for (int i = 0; i < n; i++) {
            localMax = max(localMax + arr[i], 0);
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends