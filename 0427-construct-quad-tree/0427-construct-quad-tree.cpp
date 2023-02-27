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

class Solution {
public:
    Node* builder(int r, int c, vector<vector<int>>& grid, int sz){
        bool isLeaf = true;
        int base = grid[r][c];
        
        for(int i = r; i < r+sz; i++){
            for(int j = c; j < c+sz; j++){
                if(base != grid[i][j]){
                    isLeaf = false;
                }
            }
            if(!isLeaf)
                break;
        }
        
        if(isLeaf){
            return new Node(base,true);
        }
        
        int next = sz/2;
        Node* tl = builder(r,c,grid,next);
        Node* tr = builder(r,c+next,grid,next);
        Node* bl = builder(r+next,c,grid,next);
        Node* br = builder(r+next,c+next,grid,next);

        return new Node(false, false, tl, tr, bl, br);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        
        return builder(0,0,grid,grid.size());
    }
};











