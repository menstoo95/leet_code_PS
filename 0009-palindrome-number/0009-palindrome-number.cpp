class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        string tmp = to_string(x);
        
        if(tmp.size() == 1)
            return true;
        
        for(int i = 0; i < tmp.size()/2; i++)
            if(tmp[i] != tmp[tmp.size()-1-i])
                return false;
        
        return true;
    }
};