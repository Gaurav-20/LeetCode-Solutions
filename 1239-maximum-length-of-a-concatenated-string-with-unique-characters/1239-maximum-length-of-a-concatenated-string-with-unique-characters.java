class Solution {
    public int maxLength(List<String> arr) {
        List<Integer> dp = new ArrayList<>();
        dp.add(0);
        int result = 0;
        for (String str : arr) {
            int a = 0, duplicate = 0;
            for (char c : str.toCharArray()) {
                duplicate |= a & (1 << (c - 'a'));
                a |= 1 << (c - 'a');
            }
            if (duplicate > 0) {
                continue;
            }
            for (int i = dp.size() - 1; i >= 0; i--) {
                if ((dp.get(i) & a) > 0) {
                    continue;
                }
                dp.add(dp.get(i) | a);
                result = Math.max(result, Integer.bitCount(dp.get(i) | a));
            }
            
        }
        return result;
    }
}