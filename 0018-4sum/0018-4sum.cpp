class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int l = j+1, r = nums.size()-1;
                
                while(l < r){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    
                    if(sum < target)
                        l++;
                    else if(sum > target)
                        r--;
                    else{
                        vector<int> res = {nums[i], nums[j], nums[l], nums[r]};
                        if(find(ans.begin(), ans.end(), res) == ans.end()){
                            ans.push_back(res);
                        }
                        l++;
                        r--;
                            
                    }
                }
            }
        }
        
        return ans;
    }
};