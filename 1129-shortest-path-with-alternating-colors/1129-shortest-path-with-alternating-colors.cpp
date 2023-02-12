class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> redEdges, vector<vector<int>> blueEdges) {
        vector<int> ans(n, -1);
        vector<pair<int,int>> adj[101];

        for(auto r : redEdges)
            adj[r[0]].push_back({r[1],1});
        for(auto b : blueEdges)
            adj[b[0]].push_back({b[1],0});

        queue<tuple<int,int,int>> q;
        //node, dist, color
        q.push({0, 0, -1});

        while(!q.empty()){
            int cur_node = get<0>(q.front());
            int cur_dist = get<1>(q.front());
            int cur_color = get<2>(q.front());
            q.pop();
            
            //for 0_index
            ans[cur_node] = ans[cur_node] == -1 ? cur_dist : ans[cur_node];
            
            for(int i = 0; i < adj[cur_node].size(); i++){
                int next_node = adj[cur_node][i].first;
                int next_color = adj[cur_node][i].second;
                
                if(cur_color != next_color && next_node != -1){
                    q.push({next_node, cur_dist+1, next_color});
                    adj[cur_node][i].first = -1;
                }
            }
        }

        return ans;
    }
};