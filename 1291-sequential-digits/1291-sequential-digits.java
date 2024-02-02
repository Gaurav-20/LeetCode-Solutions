class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> result = new ArrayList<>();
        String std = new String("123456789");
        for (int i = 0; i < std.length(); i++) {
            for (int j = i + 1; j < std.length(); j++) {
                String str = std.substring(i, j + 1);
                int check = Integer.parseInt(str);
                if (check >= low && check <= high) {
                    result.add(check);
                }
            }
        }
        Collections.sort(result);
        return result;
    }
}