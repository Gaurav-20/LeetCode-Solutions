class Solution {
public:
    class Tuple {
    public:
        int node;
        int mask;
        int cost;
        Tuple(int node, int mask, int cost) {
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        queue<Tuple> q;
        set<pair<int, int>> vis;
        
        int all = (1 << n) - 1;

        for (int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            Tuple thisNode(i, maskValue, 1);
            q.push(thisNode);
            vis.insert({i, maskValue});
        }

        while (!q.empty()) {
            Tuple curr = q.front();
            q.pop();
            if (curr.mask == all) {
                return curr.cost - 1;
            }
            for (auto& adj: graph[curr.node]) {
                int bothVisitedMask = curr.mask;
                bothVisitedMask |= (1 << adj); 
                Tuple thisNode(adj, bothVisitedMask, curr.cost + 1);
                if (vis.find({adj, bothVisitedMask}) == vis.end()) {
                    vis.insert({adj, bothVisitedMask});
                    q.push(thisNode);
                }
            }
        }
        return -1;
    }
};