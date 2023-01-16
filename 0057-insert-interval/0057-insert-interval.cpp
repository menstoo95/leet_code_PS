class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = 0, n = intervals.size();
        
        while(idx < n && intervals[idx][1] < newInterval[0]){
            ans.push_back(intervals[idx]);
            idx++;
        }
        
        while(idx < n && newInterval[1] >= intervals[idx][0]){
            newInterval[0] = min(intervals[idx][0], newInterval[0]);
            newInterval[1] = max(intervals[idx][1], newInterval[1]);
            idx++;
        }
        
        ans.push_back(newInterval);

        while(idx < n){
            ans.push_back(intervals[idx]);
            idx++;
        }
        
        return ans;
    }
};