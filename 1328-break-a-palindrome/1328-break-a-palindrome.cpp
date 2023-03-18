class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size() == 1)
            return "";
        
        map<string, int> hs;
        
        for(int i = 0; i < p.size()/2; i++){
            if(p[i] != 'a'){
                p[i] = 'a';
                return p;
            }
        }
        
        for(int i = p.size()-1; i >= p.size()/2; i--){
            if(p[i] != 'b'){
                p[i] = 'b';
                return p;
            }
        }
        
        return p;
    }
};