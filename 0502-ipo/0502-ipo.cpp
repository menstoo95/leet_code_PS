class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> arr;
        
        for(int i = 0; i < profits.size(); i++)
            arr.push_back({capital[i], profits[i]});
        
        sort(arr.begin(), arr.end());
        int idx = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i < k; i++){
            while(idx < arr.size() && arr[idx].first <= w){
                pq.push(arr[idx].second);
                idx++;
            }
            if(pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};