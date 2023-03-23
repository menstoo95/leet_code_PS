class Solution {
    vector<int> parent;
    
    int find(int a){
        if(parent[a] == a){
            return a;
        }
        
        return parent[a] = find(parent[a]);
    }
    
    void merger(int a, int b){
        a = find(a);
        b = find(b);
        
        if(a != b)
            parent[b] = a;
    }
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n-1 > connections.size())
            return -1;
        
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (auto c : connections) {
            merger(c[0], c[1]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        
        return ans-1;
    }
};