class Solution {
public:
    //삼성식 완탐
    unordered_map<string,bool> hs;
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(n <= 1)
            return s1[0] == s2[0];
        if(hs.find(s1+s2) != hs.end())
            return hs[s1+s2];
    
        string tmp1 = s1, tmp2 = s2;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        if(tmp1 != tmp2)
            return hs[s1+s2] = false;
        
        for (int i = 1; i <= n - 1; i++)
        {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))||(isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))))
                return hs[s1+s2] = true;
        }
        
        return hs[s1+s2] = false;
    }
};