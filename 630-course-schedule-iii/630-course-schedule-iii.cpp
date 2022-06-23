bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int time = 0;
        priority_queue<int> pq;
        for (auto course : courses) {
            int duration = course[0];
            int deadline = course[1];
            if (duration + time <= deadline) {
                time += duration;
                pq.push(duration);
            } else if (!pq.empty() && pq.top() > duration) {
                time += duration - pq.top();
                pq.pop();
                pq.push(duration);
            }
        }
        return pq.size();
    }
};