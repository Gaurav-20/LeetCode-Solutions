class Solution {
    public int fastPow(int a, int b, int m) {
        int res = 1;
        a %= m;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
    
    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < variables.length; i++) {
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            if (fastPow(fastPow(a, b, 10), c, m) == target) {
                result.add(i);
            }
        }
        return result;
    }
}