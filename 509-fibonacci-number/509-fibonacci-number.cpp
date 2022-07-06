class Solution {
public:
    int fibonacci[31] = { -1 };
    int fib(int n) {
        if (fibonacci[0] == -1) {
            fibonacci[0] = 0, fibonacci[1] = 1;
            for (int i = 2; i <= 30; i++)
                fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        return fibonacci[n];
    }
};