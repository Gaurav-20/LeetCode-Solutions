class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        int freeDays = 0, lastEnd = 0;
        for (int[] meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > lastEnd + 1) {
                freeDays += (start - lastEnd - 1);
            }
            lastEnd = Math.max(lastEnd, end);
        }
        if (lastEnd < days) {
            freeDays += (days - lastEnd);
        }
        return freeDays;
    }
}