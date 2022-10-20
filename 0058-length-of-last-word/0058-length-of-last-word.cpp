class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, flag = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ' && flag == 0)
                continue;
            else if(s[i] != ' '){
                ans++;
                flag++;
            }
            else if(s[i] == ' ' && flag)
                break;
        }
        return ans;
    }
};