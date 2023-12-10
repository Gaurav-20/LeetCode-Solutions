class Solution {
    public String predictPartyVictory(String senate) {
        int len = senate.length();
        Queue<Integer> queue1 = new LinkedList<>();
        Queue<Integer> queue2 = new LinkedList<>();
        for (int i = 0; i < len; i++) {
            if (senate.charAt(i) == 'R') {
                queue1.offer(i);
            } else {
                queue2.offer(i);
            }
        }
        while (!queue1.isEmpty() && !queue2.isEmpty()) {
            int radiantIndex = queue1.poll();
            int direIndex = queue2.poll();
            if (radiantIndex < direIndex) {
                queue1.offer(radiantIndex + len);
            } else {
                queue2.offer(direIndex + len);
            }
        }
        return (queue2.isEmpty()) ? "Radiant" : "Dire";
    }
}