class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int k) {
        long result = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
            map.put(nums2[i], map.getOrDefault(nums2[i], 0) + 1);
        } 
        for (int i = 0; i < nums1.length; i++) {
            int curr = nums1[i];
            if (curr % k == 0) {
                curr /= k;
                List<Integer> factors = getFactors(curr);
                for (Integer fact : factors) {
                    result += map.getOrDefault(fact, 0);
                }
            }
        }
        return result;
    }
    
    public List<Integer> getFactors(int n) {
        List<Integer> factors = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i * i != n) {
                    factors.add(n / i);
                }
                factors.add(i);
            }
        }
        return factors;
    }
}