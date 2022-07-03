class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        // No comparison available so direct answer
        int j = 1;
	    
        // To remove duplicate number at starting    
        while ((j < (int) nums.size()) && (nums[j] - nums[j - 1] == 0)) {
            j++;
        }
	    // push pointer forward till we are not getting two idfferent number
        if (j == (int) nums.size()) {
            return 1;
        }
	    //If all number are duplicate then 1 is answer
        int signVal = (nums[j] - nums[j-1] > 0) ? -1 : 1;
	    // signVal to predict next counting

        int totLen = 1;
	    // Variable for storing length value
    
        for (int i = j; i < (int)nums.size() ; i++) {
            if (nums[i] - nums[i - 1] > 0) {
		    // If positive then count this number if previous difference was negative
                if (signVal == -1) {
                    totLen++;
                    signVal = 1;
                }
            } else if (nums[i] - nums[i - 1] < 0) {
		    // If negative then count this number if previous difference was positive
                if (signVal == 1) {
                    totLen++;
                    signVal = -1;
                }
            }
		    // No need to write anything for duplicate handling 
            // it will automatically fall in no condition so automatically escaped
        }
        return totLen;
    }
};