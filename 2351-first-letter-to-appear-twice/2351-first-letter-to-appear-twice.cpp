class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) != m.end())
                return s[i];
            else
                m[s[i]] = 1;
        }
        return s[0];
    }
};