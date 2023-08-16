class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // O(N) Time Complexity && O(k) Space Complexity
        vector<int> res;
	    deque<int> dq;
	    for (int i = 0; i < size(nums); i++) {
            // Check if the element at the front is out of the current window bound
            // if it is then remove it as it won't be required
    		if (!dq.empty() && dq.front() == i - k) {
        		dq.pop_front();
            }
            
            // Remove all the smaller than equal to elements than the current element
            // which are already present in deque since that won't be an answer
    	    while (!dq.empty() && nums[dq.back()] <= nums[i]) {
    		    dq.pop_back();
            }
            
            // Push the current index to the deque
	        dq.push_back(i);
            
            // Start filling the result array only after reaching window size of k
            // For a window size 3, when you're done with 0, 1, 2 only then start appending
	        if (i >= k - 1) {
		        res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};