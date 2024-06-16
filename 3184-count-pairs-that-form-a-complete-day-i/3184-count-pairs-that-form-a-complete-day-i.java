class Solution {
    public int countCompleteDayPairs(int[] hours) {
        int result = 0;
        Map<Integer, Integer> map = new HashMap<>(); 
        for (int i = 0; i < hours.length; i++) {
            int curr = hours[i] % 24;
            int comp = (24 - curr) % 24;
            result += map.getOrDefault(comp, 0);
            map.put(curr, map.getOrDefault(curr, 0) + 1);
        }
        return result;
    }
}