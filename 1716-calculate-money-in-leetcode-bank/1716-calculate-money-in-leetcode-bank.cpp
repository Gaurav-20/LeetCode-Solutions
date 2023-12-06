class Solution {
public:
    int totalMoney(int n) {
        int startAmount = 0,currAmount = 0, total = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 7 == 1) {
                startAmount++;
                currAmount = startAmount;
            }
            total += currAmount;
            currAmount++;
        }
        return total;
    }
};