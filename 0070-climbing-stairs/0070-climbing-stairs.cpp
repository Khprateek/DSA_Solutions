class Solution {
    private:
    int ways(int ind,vector<int>& dp){
        if(ind <= 0) return 1;
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = ways(ind-1,dp) + ways(ind-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return ways(n-1,dp);
    }
};