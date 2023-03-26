class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> indegree(edges.size());
        vector<bool> visited(edges.size());
        int ans = -1;
        
        for(auto e : edges)
            if(e != -1)
                indegree[e]++;
        
        queue<int> q;
        for(int i = 0; i < edges.size(); i++)
            if(!indegree[i])
                q.push(i);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            int next = edges[cur];
            if(next != -1){
                indegree[next]--;
                if(indegree[next] == 0)
                    q.push(next);
            }
        }
        
        for(auto v : visited)
            cout << v << endl;
        
        for(int i = 0; i < edges.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                int cnt = 1, next = edges[i];
                while(next != i){
                    cnt++;
                    visited[next] = true;
                    next = edges[next];
                }
                ans = max(cnt, ans);
            }
        }
        
        return ans;
    }
};