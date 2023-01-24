class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board){
        int n = board.size(), idx = 0;
        vector<int> flat(n * n);
        bool flag = true;

        for(int i = n - 1; i >= 0; i--){
            if(flag)
                for(int j = 0; j < n; j++)
                    flat[idx++] = board[i][j];
            else
                for(int j = n - 1; j >= 0; j--)
                    flat[idx++] = board[i][j];
            flag = !flag;
        }

        vector<int> visited(n * n, -1);
        queue<int> q;
        q.push(0);
        visited[0] = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == n * n - 1){
                return visited[curr];
            }
            for(int i = 1; i <= 6; i++){
                int nt = curr + i;
                
                if(nt >= n * n){
                    continue;
                }
                if(flat[nt] != -1){
                    nt = flat[nt] - 1;
                }
                if(visited[nt] == -1){
                    visited[nt] = visited[curr] + 1;
                    q.push(nt);
                }
            }
        }

        return -1;
    }
};