class Solution {
    private:
    int sus(int ind, int bd,int n,vector<int> &prices,vector<vector<int>> &dp){
        if(ind == n) return 0;
        int profit = 0;
        if(dp[ind][bd] != -1) return dp[ind][bd];
        if(bd){
            profit = max(-prices[ind] + sus(ind+1,0,n,prices,dp),sus(ind+1,1,n,prices,dp));
        }
        else{
            profit = max(prices[ind] + sus(ind+1,1,n,prices,dp),sus(ind+1,0,n,prices,dp));
        }
        return dp[ind][bd] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int ind = n-1; ind >= 0; ind--){
            for(int bb = 0; bb < 2; bb++){
                if(bb == 1){
                    dp[ind][bb] = max(-prices[ind] + dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    dp[ind][bb] = max(prices[ind] + dp[ind+1][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};