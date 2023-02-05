class Solution {
public:
    bool check(vector<int> hs1, vector<int> hs2){
        for(int i = 0; i < hs1.size(); i++){
            if(hs1[i] != hs2[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> hs1(26), ans;
        if(s.size() < p.size())
            return ans;
        
        for(int i = 0; i < p.length(); i++)
            hs1[p[i]-'a']++;

        for(int i = 0; i <= s.size()-p.size(); i++){
            vector<int> hs2(26);
            for(int j = i; j < i+p.size(); j++){
                hs2[s[j]-'a']++;
            }
            if(check(hs1, hs2))
                ans.push_back(i);
        }
	
        
        return ans;
    }
};