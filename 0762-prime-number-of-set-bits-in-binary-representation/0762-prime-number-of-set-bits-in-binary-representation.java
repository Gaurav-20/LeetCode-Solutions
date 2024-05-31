class Solution {
    public final static List<Integer> primes =
        Arrays.asList(new Integer[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 });
    
    public int getSetBitsCount(int n) {
        int count = 0;
        while (n > 0) {
            count += n % 2;
            n /= 2;
        }
        return count;
    }
    
    public int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; i++) {
            int bits = getSetBitsCount(i);
            if (primes.contains(bits)) {
                result += 1;
            }
        }
        return result;
    }
}