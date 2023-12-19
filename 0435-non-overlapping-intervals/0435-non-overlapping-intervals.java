class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int result = 0;
        int left = 0;
        int right = 1;
        while (right < intervals.length) {
        	if (intervals[left][1] <= intervals[right][0]) {
        		left = right;
        	} else if (intervals[left][1] <= intervals[right][1]) {
        		result++;
        	} else if (intervals[left][1] > intervals[right][1]) {
        		result++;
        		left = right;
        	}
            right++;
        }
        return result;
    }
}