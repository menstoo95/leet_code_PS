class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0, zeros=0;

        for(auto c : s){
            if(c == '1')
                ones++;
            else
                zeros++;
            zeros = min(ones, zeros);
        }

        return zeros;
    }
};