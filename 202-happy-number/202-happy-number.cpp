class Solution {
public:
    int digitSquareSum(int n) {
        int res = 0;
        while (n) {
            int x = n % 10;
            res += x * x;
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while(slow != fast);
        return (slow == 1);
    }
};