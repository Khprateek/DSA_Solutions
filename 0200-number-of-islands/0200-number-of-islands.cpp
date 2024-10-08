class Solution {
    private:
    void bfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        for(int i = 0; i< 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] =='1'){
                if(vis[nr][nc] == -1){
                    bfs(nr,nc,grid,vis);
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        int cnt =0;
        for(int i = 0;i <n ; i++){
            for(int j =0; j <m; j++){
                if(grid[i][j] == '1' && vis[i][j] == -1){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};