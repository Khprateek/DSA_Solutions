class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n,vector<int>(m,0));
        if(s[0] == t[0]){
            dp[0][0] = 1;
        }
        else{
            dp[0][0] =0;
        }
        for(int i = 1; i< m; i++){
            if(s[0] == t[i]){
                dp[0][i] = 1;
            }
            else{
                dp[0][i] =dp[0][i-1];
            }
        }
        for(int i = 1; i< n; i++){
            if(t[0] == s[i]){
                dp[i][0] = 1;
            }
            else{
                dp[i][0] =dp[i-1][0];
            }
        }
        for(int i =1; i <n ; i++){
            for(int j = 1; j < m; j++){
                if(s[i] == t[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};