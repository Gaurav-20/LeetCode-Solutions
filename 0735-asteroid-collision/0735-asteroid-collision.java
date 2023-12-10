class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        LinkedList<Integer> list = new LinkedList<>(); // use LinkedList to simulate stack
        for (int i = 0; i < asteroids.length; i++) {
            int a = asteroids[i];
            if (a > 0 || list.isEmpty() || list.getLast() < 0) {
                list.add(a);
            } else if (list.getLast() <= -a) {
                if (list.pollLast() < -a) {
                    i--;
                }
            }
        }
        return list.stream().mapToInt(i -> i).toArray();
    }
}