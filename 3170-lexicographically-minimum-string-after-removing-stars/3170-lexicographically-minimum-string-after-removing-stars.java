class Solution {
    public String clearStars(String s) {
        char[] arr = s.toCharArray();
        Map<Character, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != '*') {
                map.putIfAbsent(arr[i], new ArrayList<>());
                map.get(arr[i]).add(i);
            } else {
                char smallest = ' ';
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (map.containsKey(ch)) {
                        smallest = ch;
                        break;
                    }
                }
                List<Integer> list = map.get(smallest);
                int idx = list.get(list.size() - 1);
                list.remove(list.size() - 1);
                if (list.size() == 0) {
                    map.remove(smallest);
                } else {
                    map.put(smallest, list);
                }
                arr[idx] = '*';
            }
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != '*') {
                builder.append(arr[i]);
            }
        }
        return builder.toString();
    }
}