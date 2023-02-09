class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_set<string> alpha[26];
        
        for(auto s : ideas){
            char c = s[0];
            alpha[c-'a'].insert(s.substr(1));
        }
        
        for(int i = 0; i < 26; i++){
            for(int j = i+1; j < 26; j++){
                long long cnt1 = 0L, cnt2 = 0L;
                
                for(auto rest : alpha[i])
                    if(alpha[j].count(rest) == 0)
                        cnt1++;
                for(auto rest : alpha[j])
                    if(alpha[i].count(rest) == 0)
                        cnt2++;
                ans += (cnt1*cnt2);
            }
        }
        
        return ans*2;
    }
};