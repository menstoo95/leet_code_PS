class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                for(int k = 1; k <= 3; k++){
                    for(int q = 1; q <= 3; q++){
                        if(i+j+k+q != s.size()) continue;
                        
                        string a = to_string(stoi(s.substr(0, i)));
                        string b = to_string(stoi(s.substr(i, j)));
                        string c = to_string(stoi(s.substr(i+j, k)));
                        string d = to_string(stoi(s.substr(i+j+k, q)));
                        
                        if(stoi(a) > 255 || stoi(b) > 255 || stoi(c) > 255 || stoi(d) > 255) continue;
                        
                        string res = a + "." + b + "." + c + "." + d;
                        if(res.size() != s.size()+3) continue;
                        ans.push_back(res);
                    }
                }
            }
        }
        
        return ans;
    }
};