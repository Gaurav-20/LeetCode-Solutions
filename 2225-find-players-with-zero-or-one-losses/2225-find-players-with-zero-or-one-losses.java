class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        List<List<Integer>> result = new ArrayList<>();
        HashSet<Integer> winner = new HashSet<>();
        Map<Integer,Integer> loser = new HashMap<>();

        for (int[] match : matches) {
            loser.put(match[1] , loser.getOrDefault(match[1] , 0) + 1);
        }
        
        for (int[] match : matches) {
            if (!loser.containsKey(match[0])) {
                winner.add(match[0]);
            }
        }

        Iterator<Integer> iterator = winner.iterator();
        List<Integer> list1 = new ArrayList<>();

        while (iterator.hasNext()) {
            list1.add(iterator.next());
        }
        Collections.sort(list1);
        result.add(list1);

        List<Integer> list2 = new ArrayList<>();
        for (Map.Entry<Integer , Integer> map : loser.entrySet()) {
            if (map.getValue() == 1) {
                list2.add(map.getKey());
            }
        }
        Collections.sort(list2);
        result.add(list2);
        return result;
    }
}