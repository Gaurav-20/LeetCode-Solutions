class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        Map<Integer, String> map = new HashMap<>();
        for (int i = 0; i < names.length; i++) {
            map.put(heights[i], names[i]);
        }
        int[] heightsDesc = Arrays.stream(heights).boxed()
            .sorted(Collections.reverseOrder())
            .mapToInt(Integer::intValue)
            .toArray();
        for (int i = 0; i < names.length; i++) {
            names[i] = map.get(heightsDesc[i]);
        }
        return names;
    }
}