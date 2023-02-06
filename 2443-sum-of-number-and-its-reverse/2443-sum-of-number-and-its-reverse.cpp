class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(!num)
            return true;
        
        for(int i = num; i >= 1; i--){
            string tmp = to_string(i);
            reverse(tmp.begin(), tmp.end());
            int res = stoi(tmp);
            if(i + res == num)
                return true;
        }
        
        return false;
    }
};