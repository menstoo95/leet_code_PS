class Solution {
public:
    bool check(stack<char> st, char ch){
        if((ch == '/' && st.top() == '/')|| ch == '.'){
            return false;
        }
        return true;
    }
    
    string simplifyPath(string path) {
        stack<string> st;
        
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/')
                continue;
            
            string tmp;
            while(path[i] != '/' && i < path.size()){
                tmp += path[i];
                i++;
            }
            if(tmp == ".")
                continue;
            else if(tmp == ".."){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(tmp);
        }
        
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if(!ans.size())
            ans = '/';
        
        return ans;
    }
};