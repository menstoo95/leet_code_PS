class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans;
        for(int i = 0; i < 2001; i++)
            ans.push_back(i);
        for(auto a : arr)
            ans[a] = 0;
        
        for(int i = 1; i < 2001; i++){
            if(ans[i])
                k--;
            if(!k)
                return i;
        }
        
        return -1;
    }
};