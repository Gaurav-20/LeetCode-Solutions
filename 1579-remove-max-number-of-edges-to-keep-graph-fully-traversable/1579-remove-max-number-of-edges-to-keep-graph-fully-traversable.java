class DSU {
    public int[] parent;
    public int[] size;
    public int numComponents;
    
    DSU(int numComponents) {
        this.parent = new int[numComponents + 1];
        this.size = new int[numComponents + 1];
        for (int i = 0; i <= numComponents; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        this.numComponents = numComponents;
    }
    
    public int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    public void unionBySize(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV) {
            return;
        }
        if (size[parentU] > size[parentV]) {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        } else {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        numComponents -= 1;
    }
    
    public boolean isSingleComponent() {
        return numComponents == 1;
    }
}

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        DSU alice = new DSU(n);
        DSU bob = new DSU(n);
        Arrays.sort(edges, (a, b) -> b[0] - a[0]);
        int edgesAdded = 0;
        for (int[] edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            if (type == 3) {
                boolean added = false;
                if (alice.findParent(u) != alice.findParent(v)) {
                    alice.unionBySize(u, v);
                    added = true;
                }
                if (bob.findParent(u) != bob.findParent(v)) {
                    bob.unionBySize(u, v);
                    added = true;
                }
                if (added) {
                    edgesAdded += 1;
                }
            }
            if (type == 2) {
                if (bob.findParent(u) != bob.findParent(v)) {
                    bob.unionBySize(u, v);
                    edgesAdded += 1;
                }
            }
            if (type == 1) {
                if (alice.findParent(u) != alice.findParent(v)) {
                    alice.unionBySize(u, v);
                    edgesAdded += 1;
                }
            }
        }
        if (alice.isSingleComponent() && bob.isSingleComponent()) {
            return edges.length - edgesAdded;
        }
        return -1;
    }
}