class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;
        for(auto a : pushed){
            st.push(a);
            while(!st.empty() && st.top() == popped[idx]){
                st.pop();
                idx++;
            }
        }
        
        return st.size() == 0;
    }
};