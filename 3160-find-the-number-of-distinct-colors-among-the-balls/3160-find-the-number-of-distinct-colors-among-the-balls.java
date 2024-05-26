class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        Map<Integer, Set<Integer>> colorToBallsMap = new HashMap<>();
        Map<Integer, Integer> ballToColorMap = new HashMap<>();
        int[] result = new int[queries.length];
        
        for (int i = 0; i < queries.length; i++) {
            int ball = queries[i][0], color = queries[i][1];
            if (ballToColorMap.containsKey(ball)) {
                if (ballToColorMap.get(ball) != color) {
                    int currColor = ballToColorMap.get(ball);
                    Set<Integer> set1 = colorToBallsMap.get(currColor);
                    set1.remove(ball);
                    if (set1.size() == 0) {
                        colorToBallsMap.remove(currColor);
                    } else {
                        colorToBallsMap.put(currColor, set1);
                    }
                    Set<Integer> set2 = colorToBallsMap.getOrDefault(color, new HashSet<>());
                    set2.add(ball);
                    colorToBallsMap.put(color, set2);
                    ballToColorMap.put(ball, color);
                }
            } else {
                ballToColorMap.put(ball, color);
                Set<Integer> set = colorToBallsMap.getOrDefault(color, new HashSet<>());
                set.add(ball);
                colorToBallsMap.put(color, set);
            }
            result[i] = colorToBallsMap.size();
        }
        return result;
    }
}