class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        deque<int> q;
        vector<int> ans;
        
        for(int i = 1; i <= m; i++)
            q.push_back(i);
        
        for(auto a : queries){
            for(int i = 0; i < m; i++){
                int cur = q.front();
                q.pop_front();
                if(cur == a){
                    ans.push_back(i);
                }
                else{
                    q.push_back(cur);
                }
            }
            q.push_front(a);
        }
        
        return ans;
    }
};