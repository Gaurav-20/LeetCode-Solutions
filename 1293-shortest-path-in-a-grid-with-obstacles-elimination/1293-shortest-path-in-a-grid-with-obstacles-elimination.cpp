struct triplet {
    int x, y, rem;
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k > n + m - 2) {
            return n + m - 2; // because n + m - 2 is the shortest path in grid
        }

        queue<triplet> q;
        unordered_set<string> seen; // better alternative to visited array in this case

        q.push({ 0, 0, k });
        int steps = 0;
        vector<int> DIRS = {0 , 1 , 0 , -1 , 0};
		
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int r = q.front().x;
                int c = q.front().y; 
                int rem = q.front().rem;
                q.pop();

                if (r == m - 1 && c == n - 1) {
                    return steps;
                }
                
                // Pushing valid childs
                for (int i = 0 ; i < 4 ; i++) {
                    int nr = r + DIRS[i];
                    int nc = c + DIRS[i + 1];
                    
                    if (nr < 0 || nc < 0 || nr == m || nc == n) {
                        continue; // out of bounds
                    }

                    int newK = rem - grid[nr][nc]; // remove the obstacle if present
                    string state = to_string(nr) + "," + to_string(nc) + "," + to_string(newK);
                    if (newK >= 0 && seen.find(state) == seen.end()) {
                        // consider only if same state wasn't seen earlier
                        q.push({ nr , nc , newK });
                        seen.insert(state);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};