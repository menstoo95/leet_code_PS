class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        
        for(auto w : weights){
            l = max(l, w);
            r += w;
        }
        cout << l << " " << r << endl;
        while(l < r){
            int mid = (l+r)/2, cur_w = 0, cur_d = 1;
            
            for(auto w : weights){
                if(cur_w + w > mid){
                    cur_d += 1;
                    cur_w = 0;
                }
                cur_w += w;
            }
            
            if(cur_d <= days)
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};