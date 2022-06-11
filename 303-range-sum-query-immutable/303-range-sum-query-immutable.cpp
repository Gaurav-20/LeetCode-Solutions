class NumArray {
public:
    vector<int> cumulative;
    NumArray(vector<int>& nums) {
        cumulative.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            cumulative.push_back(cumulative.back() + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return cumulative[right];
        } else {
            return cumulative[right] - cumulative[left - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */