class Solution {
    private:
    int ways(int i, int j,vector<vector<int>> &dp){
        if(i==1 || j == 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = ways(i,j-1,dp) + ways(i-1,j,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return ways(m,n,dp);
    }
};