class Solution {
public:
    int strStr(string haystack, string needle) {
        auto ans = haystack.find(needle);
        return ans == string::npos ? -1 : ans; 
//         int nn = needle.size(), hn = haystack.size();
        
//         for(int i = 0; i <= hn - nn; i++)
//             if(haystack[i] == needle[0] && haystack.substr(i, nn) == needle)
//                 return i;
        
//         return -1;
    }
};