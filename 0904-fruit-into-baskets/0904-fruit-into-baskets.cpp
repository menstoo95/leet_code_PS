class Solution {
public:
    int totalFruit(vector<int>& f) {
        int r = 0, l = 0;
        unordered_map<int,int> hs;
        for(r = 0, l = 0; r < f.size(); r++){
            hs[f[r]]++;
            if(hs.size() > 2){
                hs[f[l]]--;
                if(hs[f[l]] == 0)
                    hs.erase(f[l]);
                l++;
            }
        }

        return r-l;
    }
};