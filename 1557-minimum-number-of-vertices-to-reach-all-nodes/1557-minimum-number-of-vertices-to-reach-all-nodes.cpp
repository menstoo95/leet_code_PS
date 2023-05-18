class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans, tmp(n);
        
        for(auto e : edges)
            tmp[e[1]]++;
        
        for(int i = 0; i < n; i++)
            if(!tmp[i])
                ans.push_back(i);
        
        return ans;
    }
};