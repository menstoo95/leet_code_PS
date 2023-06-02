class Solution {
public:
    void dfs(int cur, vector<int> &visited, vector<int> adj[], int &cnt){
        visited[cur] = 1;
        cnt++;

        for(auto nxt: adj[cur])
            if(!visited[nxt])
                dfs(nxt, visited, adj, cnt);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];

        for(int i = 0; i < n; i++){
            long long x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];

            for(int j = 0; j < n; j++){
                if(i != j){
                    long long x2 = abs(x1 - bombs[j][0]), y2 = abs(y1 - bombs[j][1]);

                    if(x2*x2 + y2*y2 <= r*r)
                        adj[i].push_back(j);
                }
            }
        }

        int ans = -0x3f3f3f3f;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            vector<int> visited(n, 0);
            dfs(i, visited, adj, cnt);
            ans = max(ans, cnt);
        }

        return ans;
    }
};  