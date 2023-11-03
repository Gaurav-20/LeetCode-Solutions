class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> requiredOperations;
        int len = target.size(), it = 0, curr = 1;
        while (it < len) {
            if (target[it] == curr) {
                requiredOperations.push_back("Push");
            } else {
                while (target[it] != curr) {
                    requiredOperations.push_back("Push");
                    requiredOperations.push_back("Pop");
                    curr++;
                }
                requiredOperations.push_back("Push");
            }
            curr++;
            it++;
        }
        return requiredOperations;

    }
};