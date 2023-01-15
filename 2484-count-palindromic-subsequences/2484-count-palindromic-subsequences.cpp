class Solution {
public:
    int fcnt[10001][100];
    int bcnt[10001][100];
    int fdp[10001][10];
    int bdp[10001][10];
    
    int countPalindromes(string s) {
        for(int i = 0; i < s.size(); i++){
            fdp[i][s[i]-'0']++;
            for(int j = 0; j < 10 && i > 0; j++){
                if(fdp[i-1][j])
                    fdp[i][j]+=fdp[i-1][j];
            }
        }
        
        for(int i = s.size()-1; i >= 0; i--){
            bdp[i][s[i]-'0']++;
            for(int j = 0; j < 10 && i < s.size()-1; j++){
                if(bdp[i+1][j])
                    bdp[i][j]+=bdp[i+1][j];
            }
        }
        
        for(int i = 0; i < s.size(); i++){
            if(i == 0) continue;
            fdp[i][s[i]-'0']--;
            for(int j = 0; j < 10; j++){
                if(fdp[i][j]){
                    for(int k = 0; k < fdp[i][j]; k++)  
                        fcnt[i][j*10+s[i]-'0']++;
                }
            }
            for(int j = 0; j < 100; j++){
                if(fcnt[i-1][j])
                    fcnt[i][j] += fcnt[i-1][j];
            }
            fdp[i][s[i]-'0']++;
        }
        
        for(int i = s.size()-1; i >= 0; i--){
            if(i == s.size()-1) continue;
            bdp[i][s[i]-'0']--;
            for(int j = 0; j < 10; j++){
                if(bdp[i][j]){
                    for(int k = 0; k < bdp[i][j]; k++)
                        bcnt[i][j*10 + s[i]-'0']++;
                }
            }
            for(int j = 0; j < 100; j++){
                if(bcnt[i+1][j])
                    bcnt[i][j] += bcnt[i+1][j];
            }
            bdp[i][s[i]-'0']++;
        }
        
        int ans = 0;
        int sze = s.size();
        for(int i = 2; i < sze-2; i++){
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 10; k++){
                    ans = (ans + (int)((long long)fcnt[i-1][j*10+k] * (long long)bcnt[i+1][k+j*10] % 1'000'000'007LL)) % 1'000'000'007;
                }
            }
        }
        
        return ans;
    }
};