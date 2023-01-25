class Solution {
public:
    vector<int> adj[100001];
    
    vector<int> bfs(vector<int>& edges, int start){
        queue<int> q;
        vector<int> dist(edges.size(), -1);
        dist[start] = 0;
        q.push(start);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i = 0; i < adj[cur].size(); i++){
                int next = adj[cur][i];
                if(dist[next] != -1) continue;
                q.push(next);
                dist[next] = dist[cur]+1;
            }
        }
        
        return dist;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), ans = -1, minima = 0x3f3f3f3f;
        
        for(int i = 0; i < n; i++){
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        
        vector<int> dist1 = bfs(edges, node1);
        vector<int> dist2 = bfs(edges, node2);
        
        for(int i = 0; i < n; i++){
            if(dist1[i] == -1 || dist2[i] == -1) continue;
            if(minima > max(dist1[i], dist2[i])){
                ans = i;
                minima = max(dist1[i], dist2[i]);
            }
        }
        
        return ans;
    }
};