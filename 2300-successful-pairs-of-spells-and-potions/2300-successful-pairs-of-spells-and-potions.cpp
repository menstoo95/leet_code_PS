class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int n = potions.size();
        
        for(int s : spells){
            if(success % s == 0){
                long long target = success/s;

                int index = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
                int res =  potions.size() - index;

                ans.push_back(res);
            }
            else{
                long long target = success/s + 1LL;

                int index = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
                int res =  potions.size() - index;

                ans.push_back(res);
            }
        }
        
        return ans;
    }
};