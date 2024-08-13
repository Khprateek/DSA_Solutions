class Solution {
    private:
    void dfs(int n, int m,int x, int y,int dr[],int dc[], vector<vector<int>>& grid){
        grid[x][y] = 0;
        for(int i = 0; i< 4; i++){
            int r = x + dr[i];
            int c = y + dc[i];
            if(r >= 0 && r < n && c >= 0 && c <m){
                if(grid[r][c] == 1){
                    dfs(n,m,r,c,dr,dc,grid);
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[] ={-1,0,1,0};
        int dc[] ={0,1,0,-1};
        for(int j = 0; j < m ;j++){
            if(grid[0][j] == 1){
                dfs(n, m,0,j,dr, dc,grid);
            }
            if(grid[n-1][j] ==1){
                dfs(n, m,n-1,j,dr ,dc,grid);
            }
        }
        for(int i = 0 ; i< n ; i++){
            if(grid[i][0] == 1){
                dfs(n, m,i,0,dr, dc,grid);
            }
            if(grid[i][m-1] == 1){
                dfs(n, m,i,m-1,dr,dc,grid);
            }
        }
        int ans =0;
        for(int i = 0 ;i <n; i++){
            for(int j =0; j < m; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};