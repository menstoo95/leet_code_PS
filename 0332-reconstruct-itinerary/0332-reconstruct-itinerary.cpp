class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<vector<string>> ans;
    int n;

    void dfs(string& airport, vector<string>& itinerary){
        while(!adj[airport].empty()){
            string next = adj[airport].back();
            adj[airport].pop_back();
            dfs(next, itinerary);
        }
        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        for(auto a : tickets)
            adj[a[0]].push_back(a[1]);
        
        for(auto& temp : adj){
            sort(temp.second.rbegin(), temp.second.rend());
        }

        vector<string> itinerary;
        string jfk = "JFK";
        dfs(jfk, itinerary);

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};