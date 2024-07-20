class Solution {
    public String losingPlayer(int x, int y) {
        return Math.min(x, y / 4) % 2 == 1 ? "Alice" : "Bob";
    }
}