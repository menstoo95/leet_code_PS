class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        
        for(int i = 0; i < k; i++)
            if(s[i] == 'a' || s[i] == 'e' || s[i] ==  'i' || s[i] == 'o' || s[i] == 'u')
                    ans++;
        
        int l = 0, res = ans;
        for(int i = k; i < s.size(); i++){
            if(s[l] == 'a' || s[l] == 'e' || s[l] ==  'i' || s[l] == 'o' || s[l] == 'u')
                res--;
            if(s[i] == 'a' || s[i] == 'e' || s[i] ==  'i' || s[i] == 'o' || s[i] == 'u')
                res++;
            
            ans = max(res, ans);
            l++;
        }
        
        return ans;
    }
};