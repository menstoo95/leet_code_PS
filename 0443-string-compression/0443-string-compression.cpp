class Solution {
public:
    int compress(vector<char>& chars) {
        char base = chars[0];
        int cnt = 1;
        string s;
        for(int i = 1; i <= chars.size(); i++){
            if(i < chars.size() && chars[i] == base){
                cnt++;
            }
			else{
                s += base;
                if(cnt > 1)
                    s += to_string(cnt);
                
                base = i < chars.size() ? chars[i] : 0;
                cnt = 1;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
		
        return s.size();
    }
};