class Solution {
    public int kthFactor(int n, int k) {
        List<Integer> forward = new ArrayList<>();
        List<Integer> backward = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                forward.add(i);
                if (i * i != n) {
                    backward.add(n / i);
                }
            }
        }
        if (k > forward.size() + backward.size()) {
            return -1;
        }
        if (k <= forward.size()) {
            return forward.get(k - 1);
        }
        k -= forward.size();
        return backward.get(backward.size() - k);
    }
}