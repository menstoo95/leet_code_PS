class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans = 0.0;

        vector<pair<int,double>> adj[n];
        vector<double> prob(n);
        prob[start] = 1.0;

        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(auto a : adj[cur]){
                int nxt = a.first;
                double cost = a.second;

                if(cost * prob[cur] > prob[nxt]){
                    prob[nxt] = cost * prob[cur];
                    q.push(nxt);
                }
            }
        }

        return prob[end];
    }
};