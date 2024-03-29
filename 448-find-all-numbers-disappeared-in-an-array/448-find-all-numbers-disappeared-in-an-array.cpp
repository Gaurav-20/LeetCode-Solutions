class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
	    
        for (int i = 0; i < nums.size(); i++) {
            if (nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
                i--;
            }
        }
	    for (int i = 0; i < nums.size(); i++) {
		    if (nums[i] != i + 1) {
			    res.push_back(i + 1);
            }
        }
	    return res;
    }
};