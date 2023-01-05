class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1, target = points.size() - 1, s = points[0][0], e = points[0][1];
        
        for(int i = 1; i < points.size(); i++){
            int ns = points[i][0], ne = points[i][1];
            if(ne < e)
                e = ne;
            if(ns > e){
                ans++;
                s = ns;
                e = ne;
            }
        }
        
        return ans;
    }
};