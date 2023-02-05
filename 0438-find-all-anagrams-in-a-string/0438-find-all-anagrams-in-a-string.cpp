class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> hash;
        for(int i = 0; i < p.length(); i++)
            hash[p[i]]++;

        int count = hash.size();
        int win_size = p.length();
        int l = 0;
        int r = 0;

        while(r < s.length()){
            if(hash.find(s[r]) != hash.end()){
                hash[s[r]]--;
                if(hash[s[r]] == 0)
                    count--;
            }
			
            if(r-l+1 < win_size)
                r++;
            else if(r-l+1 == win_size){
                if(count == 0)
                    ans.push_back(l);

                if(hash.find(s[l]) != hash.end()){
                    hash[s[l]]++;
                    if(hash[s[l]]==1)
                        count++;
                }
                l++;
                r++;
            }
        }
        return ans;
    }
};