class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int kTickets = tickets[k];
        int time = kTickets;

        for (int i = 0; i < k; i++) {
            time += Math.min(tickets[i], kTickets);
        }
        kTickets -= 1;
        for (int i = k + 1; i < tickets.length; i++) {
            time += Math.min(tickets[i], kTickets);
        }
        return time;
    }
}