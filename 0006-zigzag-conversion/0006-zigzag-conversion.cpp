class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        
        vector<string> zig(numRows);
        string ans;
        
        int j = 0;
        bool flag = true;
        for(int i = 0; i < s.size(); i++){
            zig[j] += s[i];
            if(j == 0)
                flag = true;
            else if(j == numRows-1)
                flag = false;
            if(flag)
                j++;
            else
                j--;
        }
        for(auto tmp : zig)
            ans += tmp;
        
        return ans;
    }
};