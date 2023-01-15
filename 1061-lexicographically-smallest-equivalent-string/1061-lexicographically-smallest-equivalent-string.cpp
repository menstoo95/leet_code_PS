class Solution {
public:
    int parent[27];
    
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        
        if (a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < 27; i++)
            parent[i] = i;
        
        for(int i = 0; i < s1.size(); i++){
            // cout << s1[i] - 'a' << endl;
            union_sets(s1[i]-'a', s2[i]-'a');
        }
        
        string ans = "";
        
        for(int i = 0; i < baseStr.size(); i++){
            ans += find_set(baseStr[i]-'a') + 'a';
        }
        
        return ans;
    }
};