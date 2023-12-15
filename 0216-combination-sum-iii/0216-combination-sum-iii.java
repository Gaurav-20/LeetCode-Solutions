class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        // k = combArraySize, n = requiredSum
        List<List<Integer>> result = new ArrayList<>();
        combinations(result, new ArrayList<>(), k, 1, n);
        return result;
    }
    
    public void combinations(List<List<Integer>> result, List<Integer> comb, int k, int start, int n) {
        if (comb.size() == k && n == 0) {
            result.add(new ArrayList<Integer>(comb));
            return;
        }
        for (int num = start; num < 10; num++) {
            comb.add(num);
            combinations(result, comb, k, num + 1, n - num);
            comb.remove(comb.size() - 1);
        }
    }
}