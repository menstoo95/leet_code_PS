class Solution {
public:
    bool checker(string tmp){
        for(int i = 0; i < tmp.size()/2; i++)
            if(tmp[i] != tmp[tmp.size()-i-1])
                return false;
        return true;
    }
    
    void bt(vector<vector<string>> &ans, vector<string> &tmp, string s){
        if(s.size() == 0){
            ans.push_back(tmp);
            return;
        }
        
        for(int i = 0; i < s.size(); i++){
            string st = s.substr(0, i+1);
            
            if(checker(st)){
                tmp.push_back(st);
                bt(ans, tmp, s.substr(i+1));
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        
        bt(ans, tmp, s);
        
        return ans;
    }
};