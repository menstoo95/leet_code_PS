class Solution {
public:
    vector<int> parent;
    
    int find(int a){
        if(parent[a] == a){
            return a;
        }
        
        return parent[a] = find(parent[a]);
    }
    
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        
        if(a != b)
            parent[b] = a;

    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(auto e : edges)
            Union(e[0], e[1]);
        
        unordered_map<int, long long> hs;
        for(int i = 0; i < n; i++){
            int f = find(parent[i]);
            hs[f]++;
        }
        
        for(auto h : hs){
            ans += h.second * (n-h.second);
            n -= h.second;
        }
        
        return ans;
    }
};