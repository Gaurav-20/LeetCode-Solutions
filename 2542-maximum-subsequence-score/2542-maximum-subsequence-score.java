class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int[][] arr = new int[nums1.length][2];
        for (int i = 0; i < arr.length; i++) {
            arr[i][0] = nums1[i];
            arr[i][1] = nums2[i];
        }
        Arrays.sort(arr, (a, b) -> Integer.compare(b[1], a[1]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sumOfFirst = 0;
        for (int i = 0; i < k; i++) {
            sumOfFirst += arr[i][0];
            pq.add(arr[i][0]);
        }
        long result = arr[k - 1][1] * sumOfFirst;
        for (int i = k; i < arr.length; i++) {
            sumOfFirst += arr[i][0];
            pq.add(arr[i][0]);
            if (pq.size() > k) {
                sumOfFirst -= pq.poll();
            }
            result = Math.max(result, arr[i][1] * sumOfFirst);
        }

        return result;
    }
}