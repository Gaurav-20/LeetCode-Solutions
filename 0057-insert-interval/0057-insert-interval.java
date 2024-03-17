class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        ArrayList<int[]> mergedIntervals = new ArrayList<>(); // ArrayList to store merged intervals
        for (int[] interval : intervals) {
            // If the end of the new interval is before the start of the current interval
            if (newInterval[1] < interval[0]) {
                mergedIntervals.add(newInterval); // Add the new interval to the result
                newInterval = interval; // Update new interval to current interval for future comparisons
            } 
            // If the end of the current interval is before the start of the new interval
            else if (interval[1] < newInterval[0]) {
                mergedIntervals.add(interval); // Add the current interval to the result
            } 
            // If there is an overlap between the new interval and the current interval
            else {
                // Merge the intervals by updating the start and end of the new interval
                newInterval[0] = Math.min(newInterval[0], interval[0]); // Update start of new interval
                newInterval[1] = Math.max(newInterval[1], interval[1]); // Update end of new interval
            }
        }
        mergedIntervals.add(newInterval); // Add the final merged interval
        return mergedIntervals.toArray(new int[mergedIntervals.size()][]); // Convert ArrayList to array
    }
}