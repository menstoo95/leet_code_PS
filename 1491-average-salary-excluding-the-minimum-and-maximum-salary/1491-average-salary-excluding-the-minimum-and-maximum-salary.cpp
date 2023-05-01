class Solution {
public:
    double average(vector<int>& salary) {
        int ans = 0, mini = 0x3f3f3f3f, maxi = -0x3f3f3f3f;
        
        for(int s : salary){
            ans += s;
            mini = min(mini, s);
            maxi = max(maxi, s);
        }
        
        return (double)(ans-mini-maxi)/(salary.size()-2);
        
    }
};