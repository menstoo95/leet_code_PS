class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0, total = 0, n = satisfaction.size();
        
        for(int i = n - 1; i >= 0; --i){
            if(satisfaction[i] > -total){
                total += satisfaction[i];
                ans += total;
            }
        }
        
        return ans;
    }
};