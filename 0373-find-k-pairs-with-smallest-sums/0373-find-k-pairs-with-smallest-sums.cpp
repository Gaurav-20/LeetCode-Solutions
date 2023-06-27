class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int x : nums1) {
            // The sum and the index of the second element in nums2
            pq.push({ x + nums2[0], 0 });
        }
        // Pop the k smallest pairs from the priority queue
        while(!pq.empty() && k--) {
            int sum = pq.top().first; // Get the smallest sum
            int pos = pq.top().second; // Get the index of the second element in nums2
            res.push_back({ sum - nums2[pos], nums2[pos] }); // Add the pair to the result vector
            pq.pop(); // Remove the pair from the priority queue
            // If there are more elements in nums2, push the next pair into the priority queue
            if (pos + 1 < nums2.size()) {
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
            }
        }
        return res;
    }
};