class Solution {
    public int valueAfterKSeconds(int n, int k) {
        final int MOD = (int) 1e9 + 7;
        int[] arr = new int[n];
        Arrays.fill(arr, 1);
        for (int x = 0; x < k; x++) {
            for (int i = 1; i < n; i++) {
                arr[i] = (arr[i] + arr[i - 1]) % MOD;
            }
        }
        return arr[n - 1] % MOD;
    }
}