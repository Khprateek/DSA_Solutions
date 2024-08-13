class Solution {
    private:
    void dfs(int n, int m,int x, int y, vector<vector<char>>& board,vector<vector<bool>> &vis){
        vis[x][y] = true;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i =0; i<4; i++){
            int r = x + dr[i];
            int c = y + dc[i];
            if(r >= 0 && r < n && c >= 0 && c < m){
                if(!vis[r][c] && board[r][c] == 'O'){
                    dfs(n,m,r,c,board,vis);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int j=0; j<m ;j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(n,m,0,j,board,vis);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n,m,n-1,j,board,vis);
            }
        }
        for(int i =0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(n,m,i,0,board,vis);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(n,m,i,m-1,board,vis);
            }
        }
        for(int i =0; i< n; i++){
            for(int j =0 ;j <m;j++){
                if(!vis[i][j] && board[i][j] =='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};