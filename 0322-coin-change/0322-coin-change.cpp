class Solution {
    int pick(int ind,vector<int>& coins, int amount,vector<vector<int>> &dp){
        if(ind == 0){
            if(amount%coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        if(amount == 0) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int nottake = pick(ind-1,coins,amount,dp);
        int take = 1e9;
        if(amount >= coins[ind]){
            take = 1 +  pick(ind,coins,amount - coins[ind],dp);
        }
        return dp[ind][amount] = min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =  pick(n-1,coins,amount,dp);
        if(ans >= 1e9){
            return -1;
        }
        else return ans;
    }
};