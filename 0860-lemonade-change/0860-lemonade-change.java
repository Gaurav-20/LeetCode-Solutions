class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fiveDollarBills = 0, tenDollarBills = 0;
        // twentyDollarBills never required as a change, so no need to store
        for (int bill : bills) {
            if (bill == 5) {
                fiveDollarBills += 1;
            } else if (bill == 10) {
                if (fiveDollarBills > 0) {
                    fiveDollarBills -= 1;
                    tenDollarBills += 1;
                } else {
                    return false;
                }
            } else {
                if (tenDollarBills > 0 && fiveDollarBills > 0) {
                    // this is topmost priority choice
                    fiveDollarBills -= 1;
                    tenDollarBills -= 1;
                } else if (fiveDollarBills > 2) {
                    fiveDollarBills -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}