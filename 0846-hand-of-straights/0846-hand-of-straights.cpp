class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize)
            return false;
        
        unordered_map<int,int> hs;
        
        for(auto h : hand)
            hs[h]++;
        
        sort(hand.begin(), hand.end());
        
        for(auto a : hand){
            if(!hs[a]) continue;
            
            for(int i = 0; i < groupSize; i++){
                if(!hs[a+i]--)
                    return false;
            }            
        }
        
        return true;
        
    }
};