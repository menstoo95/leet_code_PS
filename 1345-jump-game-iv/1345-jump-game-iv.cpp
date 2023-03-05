class Solution {
public:
    int minJumps(vector<int> arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> hs;
        //check arr[i] == arr[j]
        for(int i = 0; i < n; i++)
            hs[arr[i]].push_back(i);

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> ans(n, 0x3f3f3f3f);
        ans[0] = 0;

        while(!q.empty()){
            int idx = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(idx >= 0 && idx < n){
                if(idx == n - 1)
                    return dist;

                if(idx - 1 >= 0 && dist + 1 < ans[idx - 1]){
                    ans[idx - 1] = dist + 1;
                    q.push({idx - 1, dist + 1});
                }

                if(idx + 1 < n && dist + 1 < ans[idx + 1]){
                    ans[idx + 1] = dist + 1;
                    q.push({idx + 1, dist + 1});
                }

                for(auto i : hs[arr[idx]]){
                    if(i != idx && dist + 1 < ans[i]){
                        ans[i] = dist + 1;
                        q.push({i, dist + 1});
                    }
                }

                hs.erase(arr[idx]);
            }
        }

        return -1;
    }
};