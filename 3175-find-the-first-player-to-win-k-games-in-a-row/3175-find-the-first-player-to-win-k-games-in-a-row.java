class Solution {
    public int findWinningPlayer(int[] skills, int k) {
        Deque<Integer> deque = new ArrayDeque<>();
        Map<Integer, Integer> wins = new HashMap<>();
        int maxSkill = 0;
        for (int i = 0; i < skills.length; i++) {
            deque.addLast(i);
            maxSkill = Math.max(maxSkill, skills[i]);
        }
        while (true) {
            int player1 = deque.removeFirst();
            int player2 = deque.removeFirst();
            if (skills[player1] == maxSkill) {
                return player1;
            }
            if (skills[player2] == maxSkill) {
                return player2;
            }
            if (skills[player1] > skills[player2]) {
                deque.addFirst(player1);
                deque.addLast(player2);
                wins.put(player1, wins.getOrDefault(player1, 0) + 1);
                if (wins.get(player1) == k) {
                    return player1;
                }
            } else {
                deque.addFirst(player2);
                deque.addLast(player1);
                wins.put(player2, wins.getOrDefault(player2, 0) + 1);
                if (wins.get(player2) == k) {
                    return player2;
                }
            }
        }
    }
}