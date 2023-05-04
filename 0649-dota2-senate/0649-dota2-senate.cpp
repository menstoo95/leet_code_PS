class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        
        for(int i = 0; i < senate.size(); i++)
            senate[i] == 'R' ? radiant.push(i) : dire.push(i);
        
        while(!radiant.empty() && !dire.empty()){
            int ridx = radiant.front(), didx = dire.front();
            radiant.pop();
            dire.pop();
            
            if(ridx < didx)
                radiant.push(ridx+senate.size());
            else
                dire.push(didx+senate.size());
        }
        
        if(dire.empty())
            return "Radiant";
        else
            return "Dire";
    }
};