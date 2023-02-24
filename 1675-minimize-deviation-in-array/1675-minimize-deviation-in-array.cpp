class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]&1)
                nums[i] = nums[i]*2;
        }
        
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        
        int ans = maxi - mini;
        
        priority_queue<int> pq;
        for(auto n : nums)
            pq.push(n);
        
        while(true){
            if(pq.top()&1)
                break;
            int cur = pq.top();
            pq.pop();
            ans = min(ans, cur - mini);
            cur = cur/2;
            mini = min(cur, mini);
            pq.push(cur);
        }
        
        ans = min(ans, pq.top()-mini);
        
        return ans;
    }
};
/*
2 2 6 4
2 2 3 4
*/