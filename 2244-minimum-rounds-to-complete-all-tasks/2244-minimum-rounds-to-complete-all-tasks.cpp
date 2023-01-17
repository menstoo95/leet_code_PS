class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> hs;
        int ans = 0;
        
        for(auto t : tasks)
            hs[t]++;
        
        for(auto h : hs){
            if(h.second == 1)
                return -1;
            if(!(h.second%3))
                ans += h.second/3;
            else
                ans += h.second/3 + 1;
        }
        
        return ans;
    }
};