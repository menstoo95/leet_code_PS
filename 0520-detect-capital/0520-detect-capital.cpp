class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
            return true;
        
        bool all = isupper(word[0]) && isupper(word[1]), none = islower(word[0]), part = isupper(word[0]) && islower(word[1]);
        
        for(int i = 1; i < word.size(); i++){
            if(all && islower(word[i]))
                return false;
            if(none && isupper(word[i]))
                return false;
            if(part && isupper(word[i]))
                return false;
        }
        
        return true;
    }
};