class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        if(k >= n) {
            return maxi;
        }
        int i = 0, j = 1;
        int wins = 0;
        while (i < n && j < n) {
            if (wins == k) {
                return arr[i];
            }
            if (arr[i] > arr[j]) {
                j++;
                wins++;
            } else {
                i = j;
                j++;
                wins = 1;
            }
        }
        return arr[i];
    }
};