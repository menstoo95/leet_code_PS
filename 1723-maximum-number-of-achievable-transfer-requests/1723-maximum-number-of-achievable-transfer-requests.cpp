class Solution {
public:
    vector<int> topo;
    int ans = 0;

    void bt(int idx, vector<vector<int>>& requests, int res){
        if(idx == requests.size()){
            for(auto a : topo)
                if(a)
                    return;
            
            ans = max(ans, res);
            return;
        }

        topo[requests[idx][0]]--;
        topo[requests[idx][1]]++;
        bt(idx+1, requests, res+1);

        topo[requests[idx][0]]++;
        topo[requests[idx][1]]--;
        bt(idx+1, requests, res);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        topo.resize(n);
        bt(0, requests, 0);

        return ans;
    }
};