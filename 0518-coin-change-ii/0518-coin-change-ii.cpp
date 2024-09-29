class Solution {
    private:
    int ways(int ind,vector<int>& coins,int amount,vector<vector<int>> &dp){
        if(ind < 0) return 0;
        if(amount == 0) return 1;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notpick = ways(ind-1,coins,amount,dp);
        int pick = 0;
        if(amount >= coins[ind]){
            pick = ways(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount] = pick + notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return ways(n-1,coins,amount,dp);
    }
};