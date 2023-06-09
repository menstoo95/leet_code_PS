class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto c : letters)
            if(target < c)
                return c;
        
        return letters[0];
    }
};