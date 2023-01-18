class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> hs;
        string ans = "";
        hs["&quot;"] = "\"";
        hs["&apos;"] = "\'";
        hs["&amp;"] = "&";
        hs["&gt;"] = ">";
        hs["&lt;"] = "<";
        hs["&frasl;"] = "/";
        
        for(int i = 0; i < text.size(); i++){
            if(text[i] == '&'){
                string res = "";
                int j;
                
                for(j = i; j < text.size(); j++){
                    res += text[j];
                    if(text[j] == ';')
                        break;
                    if(text[j] == ' ')
                        break;
                }
                
                if(j == text.size() || text[j] == ' '){
                    ans.push_back(text[i]);
                    continue;
                }
                else{
                    if(hs.find(res) == hs.end()){
                        cout << "hey~" << endl;
                        ans.push_back(text[i]);
                        continue;
                    }
                    else{
                        ans += hs[res];
                        i += j-i;
                    }
                }
            }
            else{
                ans.push_back(text[i]);
            }
        }
        
        return ans;
    }
};