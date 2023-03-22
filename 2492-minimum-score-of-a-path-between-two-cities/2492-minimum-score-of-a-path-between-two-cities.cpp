class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n+1);
        for(auto r : roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        
        queue<int> q;
        vector<bool> visited(n+1);
        q.push(1);
        visited[1] = true;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int i = 0; i < adj[cur].size(); i++){
                int next = adj[cur][i];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        
        int ans = INT_MAX;
        for(auto a : roads){
            int from = a[0], to = a[1], cost = a[2];
            if(visited[from] && visited[to] && cost < ans){
                ans = cost;
            }
        }
        
        return ans;
    }
};