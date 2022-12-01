class Solution {
public:
    unordered_map<char, int> vowels = {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
    
    bool halvesAreAlike(string s) {
        int n = s.size();
        int an = 0, bn = 0;
        
        for(int i = 0; i < n/2; i++){
            if(vowels[tolower(s[i])])
                an++;
            if(vowels[tolower(s[n-i-1])])
                bn++;
        }
        
        return an==bn;
    }
};