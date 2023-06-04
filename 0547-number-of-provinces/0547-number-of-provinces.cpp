class Solution {
public:
    void dfs(int cur, vector<vector<int>> &graph, int sz, vector<bool> &visited){
        visited[cur] = true;
        
        for(int i = 0; i < graph[cur].size(); i++){
            if(graph[cur][i] == 1 && !visited[i]){
                dfs(i, graph, sz, visited);
            }
        }
        
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size(), ans = 0;
        vector<bool> visited(sz, false);
        
        for(int i = 0; i < sz; i++){
            if(!visited[i]){
                ans++;
                dfs(i, isConnected, sz, visited);
            }
        }

		return ans;
    }
};