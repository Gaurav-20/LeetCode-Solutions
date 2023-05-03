class Solution {
public:
    vector<int> solve(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i: nums2) {
            mp[i]++;
        }
        for (int i: nums1) {
            if (mp.count(i) == 0) {
                res.push_back(i);
                mp[i]++;
            }
        }
        return res;
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        res[0] = solve(nums1, nums2);
        res[1] = solve(nums2, nums1);
        return res;
    }
};