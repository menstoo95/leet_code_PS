class Solution {
public:
    long long minimumFuelCost(vector<vector<int>> roads, int seats) {
        vector<vector<int>> adj(roads.size()+1);
        vector<int> cnt(roads.size()+1);

        for(auto road : roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            cnt[road[1]]++;
            cnt[road[0]]++;
        }

        //node
        queue<int> q;
        for(int i = 1; i < cnt.size(); i++){
            if(cnt[i] == 1){
                q.push(i);
            }
        }

        vector<int> rep(roads.size()+1, 1);
        long long ans = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            ans += ceil((double)rep[cur] / seats);
            
            for(int i = 0; i < adj[cur].size(); i++){
                int next = adj[cur][i];
                cnt[next]--;
                rep[next] += rep[cur];
                
                if(cnt[next] == 1 && next != 0){
                    q.push(next);
                }
            }
        }

        return ans;
    }
};