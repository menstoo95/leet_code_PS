class Solution {
public:
    int bestClosingTime(string customers) {
        int l = 0, r = 0;
        
        for(auto e : customers)
            if(e == 'Y')
                r++;
        
        
        int ans = 0, pnt = r;
        for(int i = 0; i < customers.size(); i++){
            if(customers[i] == 'N'){
                l++;
            }
            else{
                r--;
            }
            if(l+r < pnt){
                pnt = l+r;
                ans = i+1;
            }
        }
        
        return ans;
    }
};