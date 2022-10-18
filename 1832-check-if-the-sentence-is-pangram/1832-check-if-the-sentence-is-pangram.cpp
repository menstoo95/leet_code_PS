class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alpha(26);
        
        for(char c : sentence)
            alpha[c-'a']++;
        
        for(int a : alpha)
            if(!a)
                return false;
        
        return true;
    }
};