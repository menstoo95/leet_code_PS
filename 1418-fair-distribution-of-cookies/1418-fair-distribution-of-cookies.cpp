class Solution {
public:
    int ans = 0x3f3f3f3f;

    void bt(int idx, vector<int>& cookies, vector<int>& kth, int k){
        if(idx == cookies.size()){
            int local_max = -0x3f3f3f3f;

            for(auto a : kth)
                local_max = max(local_max, a);
            
            ans = min(ans, local_max);
            return;
        }

        for(int i = 0; i < k; i++){
            kth[i] += cookies[idx];
            bt(idx+1, cookies, kth, k);
            kth[i] -= cookies[idx];
        }

        return;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kth(k, 0);
        bt(0, cookies, kth, k);
        
        return ans;
    }
};