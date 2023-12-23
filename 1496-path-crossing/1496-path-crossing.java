class Solution {
    public boolean isPathCrossing(String path) {
        Set<Pair<Integer, Integer>> visited = new HashSet<>();
        int xCoordinate = 0, yCoordinate = 0;
        visited.add(new Pair(xCoordinate, yCoordinate));
        for (int i = 0; i < path.length(); i++) {
            char curr = path.charAt(i);
            if (curr == 'N') {
                yCoordinate--;
            } else if (curr == 'E') {
                xCoordinate++;
            } else if (curr == 'W') {
                xCoordinate--;
            } else {
                yCoordinate++;
            }
            Pair<Integer, Integer> pair = new Pair(xCoordinate, yCoordinate);
            if (visited.contains(pair)) {
                return true;
            }
            visited.add(pair);
        }
        return false;
    }
}