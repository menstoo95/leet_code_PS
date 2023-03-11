class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == '*')
                star.push(i);
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        while(!st.empty() && !star.empty() && st.top() < star.top()){
            star.pop();
            st.pop();
        }

        return st.empty();
    }
};