class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto t : tokens){ 
            if(t.size() > 1 || isdigit(t[0]))
                st.push(stoi(t));
            else{
                int b = st.top();st.pop();
                int a = st.top();st.pop();
                if(t == "+")
                    a += b;
                else if(t == "-")
                    a -= b;
                else if(t == "*")
                    a *= b;
                else
                    a /= b;
                
                st.push(a);
            }
        }
        
        return st.top();
    }
};