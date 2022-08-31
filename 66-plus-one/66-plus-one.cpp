class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1; // since we want to add 1
        for (int i = n - 1; i >= 0; i--) {
            int curr = digits[i] + carry;
            digits[i] = curr % 10;
            carry = curr / 10;
            if (carry == 0) {
                break;
            }
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};