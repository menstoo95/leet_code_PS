class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(st.empty() || st.top() != '(')
                    return false;
                else{
                    st.pop();
                    continue;
                }
            }
            else if(s[i] == '}'){
                if(st.empty() || st.top() != '{')
                    return false;
                else{
                    st.pop();
                    continue;
                }
            }
            else if(s[i] == ']'){
                if(st.empty() || st.top() != '[')
                    return false;
                else{
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        
        if(!st.empty())
            return false;
        return true;
    }
};