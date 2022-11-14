class Solution {
public:
    vector<int> parent;
    
    int find_(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            return find_(parent[x]);
        }
    }

    void union_(int x, int y){
        x = find_(x);
        y = find_(y);

        parent[y] = x;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        parent = vector<int>(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    union_(i,j);
            
        int cnt = 0;
        for(int i = 0; i < n; i++) 
            if(parent[i] == i) cnt++;
        
        return n - cnt;
    }
    
};