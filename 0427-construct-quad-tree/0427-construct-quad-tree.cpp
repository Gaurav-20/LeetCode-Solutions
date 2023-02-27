/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

Node* zero = new Node(false, true);
Node* one = new Node(true, true);

class Solution {
public:
    Node* solve(vector<vector<int>>& grid, int r, int c, int n) {
        if (n == 1) {
            return grid[r][c] == 1 ? one : zero;
        }
        int mid = n / 2;
        Node* topLeft = solve(grid, r, c, mid);
        Node* topRight = solve(grid, r, c + mid, mid);
        Node* botLeft = solve(grid, r + mid, c, mid);
        Node* botRight = solve(grid, r + mid, c + mid, mid);
        if (topLeft == topRight && botLeft == botRight && topLeft == botLeft) {
            return topLeft;
        }
        return new Node(false, false, topLeft, topRight, botLeft, botRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};