class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            int curr = num[i] + k;
            num[i] = curr % 10;
            k = curr / 10;
        }
        while (k > 0) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};