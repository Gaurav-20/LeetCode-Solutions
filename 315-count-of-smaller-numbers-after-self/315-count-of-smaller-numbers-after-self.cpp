#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        ordered_set o;

        for (int i = n - 1; i >= 0; i--) {
            if (o.empty())
                counts[i] = 0;
            else
                counts[i] = o.order_of_key(nums[i]);

            o.insert(nums[i]);   
        }
        return counts;
    }
};