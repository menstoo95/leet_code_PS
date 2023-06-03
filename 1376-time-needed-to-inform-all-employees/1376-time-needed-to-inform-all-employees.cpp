class Solution {
public:
    int dfs(int headId, vector<int>& informTime,vector<int> adj[]){
        int res = 0;

        for(auto a : adj[headId])
            res = max(res, dfs(a, informTime, adj));

        return informTime[headId] + res;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n+1];

        for(int i = 0; i < manager.size(); i++)
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        
        return dfs(headID, informTime, adj);
    }
};