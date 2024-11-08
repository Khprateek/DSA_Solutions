class Solution {
    private:
    int sus(int r, int c,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int n = matrix.size();
        if(c < 0 || c >= n) return 1e9;
        if(r == 0) return matrix[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = matrix[r][c] + min(sus(r-1,c-1,matrix,dp),min(sus(r-1,c,matrix,dp),sus(r-1,c+1,matrix,dp)));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i =0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int r = 1; r< n; r++){  
            for(int c = 0; c <n; c++){
                int left = 1e9 + matrix[r][c];
                int right = 1e9 + matrix[r][c];
                int top = dp[r-1][c] + matrix[r][c];
                if(c > 0) left = dp[r-1][c-1] + matrix[r][c];
                if(c < n-1) right = dp[r-1][c+1] + matrix[r][c];
                dp[r][c] = min(left,min(top,right));
            }
        }
        for(int i = 0; i< n; i++){
            mini = min(dp[n-1][i],mini);
        }
        return mini;
    }
};