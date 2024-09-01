class Solution {
    private:
    int sus(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(r == 0 && c == 0) return grid[r][c];
        if(r < 0 || c < 0) return 1e9;
        if(dp[r][c] != -1) return dp[r][c];
        int top = grid[r][c] + sus(r -1, c, grid,dp);
        int left = grid[r][c] + sus(r, c -1, grid,dp);
        return dp[r][c] = min(top,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+2,vector<int>(n+2,-1));
        return sus(m-1,n-1,grid,dp);
    }
};