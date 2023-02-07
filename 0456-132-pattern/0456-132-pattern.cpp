class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int nk = -0x3f3f3f3f;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < nk)
                return true;
            else{
                while(!st.empty() && st.top() < nums[i]){
                    nk = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        
        return false;
    }
};