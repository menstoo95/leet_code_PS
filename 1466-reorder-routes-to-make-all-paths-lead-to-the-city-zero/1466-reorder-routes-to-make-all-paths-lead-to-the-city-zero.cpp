class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> adj[n];
        int ans = 0;
        
        for(auto c : connections){
            adj[c[0]].push_back({c[1], 1});
            adj[c[1]].push_back({c[0], 0});
        }
        
        queue<int> q;
        vector<bool> visited(n);
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int i = 0; i < adj[cur].size(); i++){
                int next = adj[cur][i].first;
                int dir = adj[cur][i].second;
                
                if(!visited[next]){
                    visited[next] = 1;
                    q.push(next);
                    ans += dir;
                }
            }
        }
        
        return ans;
    }
};