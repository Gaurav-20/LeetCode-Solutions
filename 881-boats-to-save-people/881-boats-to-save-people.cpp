class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int len = people.size();
        sort(people.begin(), people.end());
        int boats = 0;
        int i = 0;
        int j = len - 1;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
            }
            boats++;
            j--;
        }
        return boats;
    }
};