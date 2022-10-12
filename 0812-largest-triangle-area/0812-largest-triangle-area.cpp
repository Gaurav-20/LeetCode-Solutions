class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    res = max(res, 
                        abs(
                            (points[j][0] - points[i][0]) * (points[k][1] - points[i][1]) - 
                            (points[k][0] - points[i][0]) * (points[j][1] - points[i][1])
                        )
                    ); // avoiding costly sqrt operation since values are integers only
                }
            }
        }
        return res / 2.0;
    }
};