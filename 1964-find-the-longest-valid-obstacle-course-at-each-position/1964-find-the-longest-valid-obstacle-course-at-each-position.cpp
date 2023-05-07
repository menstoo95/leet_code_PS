class Solution {
public:   
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans, lis;
        
        for (int i = 0; i < obstacles.size(); i++) {
            int l = 0, r = lis.size();
            while (l < r) {
                int mid = (l + r) / 2;
                if (lis[mid] <= obstacles[i])
                    l = mid + 1;
                else
                    r = mid;
            }
            ans.push_back(l + 1);
            
            if (lis.size() == l)
                lis.push_back(obstacles[i]);
            lis[l] = obstacles[i];
        }
        
        return ans;
    }
};