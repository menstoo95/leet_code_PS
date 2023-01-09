class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for(string s : strs){
            bool flag = true;
            for(int i = 0; i < s.size(); i++){
                if(!isdigit(s[i])){
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                ans = max(ans, stoi(s));
            else
                ans = max(ans, (int)s.size());
        }
        
        return ans;
    }
};