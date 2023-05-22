class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        vector<vector<int>> buckets(nums.size());
        for (auto& it : mp) {
            buckets[it.second - 1].push_back(it.first);
        }
        reverse(buckets.begin(), buckets.end());
        vector<int> res;
        for (auto& bucket : buckets) {
            if (res.size() >= k) {
                break;
            } else if (bucket.size() == 0) {
                continue;
            } else {
                for (int& b : bucket) {
                    res.push_back(b);
                }
            }
        }
        return res;
    }
};