class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        int[] hor = new int[hFences.length + 2];
        int[] ver = new int[vFences.length + 2];
        for (int i = 1; i < hor.length - 1; i++) {
            hor[i] = hFences[i - 1];
        }
        hor[0] = 1;
        hor[hor.length - 1] = m;
        for (int i = 1; i < ver.length - 1; i++) {
            ver[i] = vFences[i - 1];
        }
        ver[0] = 1;
        ver[ver.length - 1] = n;
        Set<Integer> differences = new HashSet<Integer>();
        long result = -1;
        for (int i = 0; i < hor.length; i++) {
            for (int j = i + 1; j < hor.length; j++) {
                differences.add(Math.abs(hor[i] - hor[j]));
            }
        }
        for (int i = 0; i < ver.length; i++) {
            for (int j = i + 1; j < ver.length; j++) {
                if (differences.contains(Math.abs(ver[i] - ver[j]))) {
                    result = Math.max(result, Math.abs(ver[i] - ver[j]));
                }
            }
        }
        if (result == -1) {
            return -1;
        }
        return (int) ((result * result) % 1000000007);
    }
}