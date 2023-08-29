class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int earliestHour = -1;
        int score = 0, maxScore = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                score++;
            } else {
                score--;
            }
            if (score > maxScore) {
                maxScore = score;
                earliestHour = i;
            }
        }
        return (earliestHour == -1) ? 0 : earliestHour + 1;
    }
};