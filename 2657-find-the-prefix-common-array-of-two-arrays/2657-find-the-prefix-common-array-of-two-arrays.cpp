class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;
        int n = A.size();
        vector<int> res(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            freq[B[i]]++;
            if (freq[A[i]] == 2) {
                count++;
            }
            if (A[i] != B[i] && freq[B[i]] == 2) {
                count++;
            }
            res[i] = count;
        }
        return res;
    }
};