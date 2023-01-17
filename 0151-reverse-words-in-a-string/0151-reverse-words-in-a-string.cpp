#include <string>

class Solution {
public:
    vector<string> split(string str, char deli){
        stringstream ss(str);
        vector<string> res;
        string tmp;
        
        while(ss >> tmp){
            res.push_back(tmp);
        }
        
        return res;
    }
    
    string reverseWords(string s) {
        vector<string> res = split(s, ' ');
        string ans = "";
        
        for(int i = res.size()-1; i > 0; i--){
            ans += res[i] + ' ';
        }
        
        return ans + res[0];
    }
};