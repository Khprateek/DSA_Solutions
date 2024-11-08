class Solution {
    private:
    int sus(int r, int c,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int n = matrix.size();
        if(c < 0 || c >= n) return 1e9;
        if(r >= n-1) return matrix[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = matrix[r][c] + min(sus(r+1,c-1,matrix,dp),min(sus(r+1,c,matrix,dp),sus(r+1,c+1,matrix,dp)));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i = 0; i< n; i++){
            mini = min(mini,sus(0,i,matrix,dp));
        }
        return mini;
    }
};